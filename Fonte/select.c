//BufferPool
#include "buffend.h"

/* ----------------------------------------------------------------------------------------------
    Objetivo:
    Parametros:
    Retorno:
   ---------------------------------------------------------------------------------------------*/

// Verifica se todas as colunas especificadas existem no esquema.
int allColumnsExistsSelect(rc_select *s_select, tp_table *esquema);
int onSelect(rc_select *s_select, char *nomecampo);

void selectQ(rc_select *s_select) {

    int j,erro, x, p, cont=0, i, flag;
    struct fs_objects objeto;

    if (!verificaNomeTabela(s_select->objName)) {
        printf("\nERROR: relation \"%s\" was not found.\n\n\n", s_select->objName);
        return;
    }

    objeto = leObjeto(s_select->objName);

    tp_table *esquema = leSchema(objeto);

    if (esquema == ERRO_ABRIR_ESQUEMA) {
        printf("ERROR: schema cannot be created.\n");
        free(esquema);
        return;
    }

	if (!allColumnsExistsSelect(s_select, esquema)) {
        free(esquema);
        return;
	}
	
    tp_buffer *bufferpoll = initbuffer();

    if (bufferpoll == ERRO_DE_ALOCACAO) {
        free(bufferpoll);
        free(esquema);
        printf("ERROR: no memory available to allocate buffer.\n");
        return;
    }

    erro = SUCCESS;
    for (x = 0; erro == SUCCESS; x++)
		erro = colocaTuplaBuffer(bufferpoll, x, esquema, objeto);

    int ntuples = --x;
	p = 0;
	
	while (x) {
	    column *pagina = getPage(bufferpoll, esquema, objeto, p);
	    if (pagina == ERRO_PARAMETRO) {
            printf("ERROR: could not open the table.\n");
            free(bufferpoll);
            free(esquema);
            return;
	    }

	    if (!cont) {
			flag = 1;
	        for (j=0; j < objeto.qtdCampos; j++) {
				if (onSelect(s_select, pagina[j].nomeCampo)) {
					if (flag) flag = 0;
					else printf("|");
					if (pagina[j].tipoCampo == 'S')
						printf(" %-20s ", pagina[j].nomeCampo);
					else
						printf(" %-10s ", pagina[j].nomeCampo);
				}
	        }
	        printf("\n");
	        flag = 1;
	        for (j=0; j < objeto.qtdCampos; j++) {
				if (onSelect(s_select, pagina[j].nomeCampo)) {
					if (flag) flag = 0;
					else printf("+");
					printf("%s", pagina[j].tipoCampo == 'S' ? "----------------------" : "------------");
				}
	        }
	        printf("\n");
	    }
	    cont++;
	    for (i=0; i < bufferpoll[p].nrec; i++) {
			flag = 1;
			for (j=0; j < objeto.qtdCampos; j++) {
				int jj = j + (i * objeto.qtdCampos);
				if (onSelect(s_select, pagina[jj].nomeCampo)) {
					if (flag) flag = 0;
					else printf("|");
					if (pagina[jj].tipoCampo == 'S') {
						printf(" %-20s ", pagina[jj].valorCampo);
					} else if (pagina[jj].tipoCampo == 'I') {
						int *n = (int *)&pagina[jj].valorCampo[0];
						printf(" %-10d ", *n);
					} else if (pagina[jj].tipoCampo == 'C') {
						printf(" %-10c ", pagina[jj].valorCampo[0]);
					} else if (pagina[jj].tipoCampo == 'D'){
						double *n = (double *)&pagina[jj].valorCampo[0];
						printf(" %-10f ", *n);
					}
				}
			}
			printf("\n");
		}
    	x-=bufferpoll[p++].nrec;
    }
    printf("\n(%d %s)\n\n", ntuples, 1 >= ntuples ? "row" : "rows");

    free(bufferpoll);
    free(esquema);
}

int allColumnsExistsSelect(rc_select *s_select, tp_table *esquema) {
	int i;
	if (!s_select->columnName) return 0;

	for (i = 0; i < s_select->N; i++) {
		while (esquema != NULL) {
			if (strcmp(s_select->columnName[i], esquema->nome) == 0) {
				break;
			}
			esquema = esquema->next;
		}
		if (esquema == NULL) {
			printf("ERROR: column \"%s\" does not exist.\n", s_select->columnName[i]);
			return 0;
		}
	}
	return 1;
}

int onSelect(rc_select *s_select, char *nomecampo) {
	int i;
	for (i = 0; i < s_select->N; i++) {
		if (strcmp(s_select->columnName[i], nomecampo) == 0) return 1;
	}
	return 0;
}
