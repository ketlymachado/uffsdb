//BufferPool
#include "buffend.h"

/* ----------------------------------------------------------------------------------------------
    Objetivo:
    Parametros:
    Retorno:
   ---------------------------------------------------------------------------------------------*/

// Verifica se todas as colunas especificadas existem no esquema.
int allColumnsExistsSelect(rc_select *s_select, tp_table *esquema, tp_table *esquemaj);
void makeAllPredicates(rc_select *s_select, tp_table *esquema);
int existColumn(int O, int D, rc_select *s_select, tp_table *esquema, tp_table *esquemaj);
int onSelect(rc_select *s_select, char *nomecampo);
int compatibleTypes(char t1, char t2, char *operator);
int verifySimpleWhere(rc_select *s_select);
int verifyObjectWhere(rc_select *s_select, column *pg, int i, int L);

void selectQ(rc_select *s_select) {

    int j, erro, x, p, cont=0, i, flag;
    struct fs_objects objeto, objetoj;
	tp_table *esquema, *esquemaj;
	
    if (!verificaNomeTabela(s_select->objName)) {
        printf("\nERROR: relation \"%s\" was not found.\n\n\n", s_select->objName);
        return;
    }
    
    if (s_select->juncao && !verificaNomeTabela(s_select->joinObjName)) {
        printf("\nERROR: relation \"%s\" was not found.\n\n\n", s_select->joinObjName);
        return;
    }
	
    objeto = leObjeto(s_select->objName);
    if (s_select->juncao) objetoj = leObjeto(s_select->joinObjName);

    esquema = leSchema(objeto);
    if (s_select->juncao) esquemaj = leSchema(objetoj);

    if (esquema == ERRO_ABRIR_ESQUEMA) {
        printf("ERROR: schema cannot be created.\n");
        free(esquema);
        return;
    }
    
    if (s_select->juncao && esquemaj == ERRO_ABRIR_ESQUEMA) {
        printf("ERROR: schema cannot be created.\n");
        free(esquema);
        free(esquemaj);
        return;
    }
    
    if (strcmp(s_select->columnName[0], "*") == 0) {
		makeAllPredicates(s_select, esquema);
	}
    
	if (!allColumnsExistsSelect(s_select, esquema, esquemaj)) {
        free(esquema);
        free(esquemaj);
        return;
	}
	
	if (s_select->selecao && s_select->W.LPT == 'O') {
		if (!existColumn(0, 0, s_select, esquema, esquemaj)) {
			free(esquema);
			free(esquemaj);
			return;
		}
	}
	
	if (s_select->selecao && s_select->W.RPT == 'O') {
		if (!existColumn(0, 1, s_select, esquema, esquemaj)) {
			free(esquema);
			free(esquemaj);
			return;
		}
	}
	
	if (s_select->juncao && s_select->J.LPT == 'O') {
		if (!existColumn(1, 0, s_select, esquema, esquemaj)) {
			free(esquema);
			free(esquemaj);
			return;
		}
	}
	
	if (s_select->juncao && s_select->J.RPT == 'O') {
		if (!existColumn(1, 1, s_select, esquema, esquemaj)) {
			free(esquema);
			free(esquemaj);
			return;
		}
	}
	
	if (s_select->selecao && (!compatibleTypes(s_select->W.LPT, s_select->W.RPT, s_select->W.operator))) {
		printf("ERROR: Invalid comparison.\n");
		free(esquema);
		free(esquemaj);
		return;
	}
	
	if (s_select->juncao && (!compatibleTypes(s_select->J.LPT, s_select->J.RPT, s_select->J.operator))) {
		printf("ERROR: Invalid comparison.\n");
		free(esquema);
		free(esquemaj);
		return;
	}
	
	if (s_select->selecao && s_select->W.LPT == 'A') {
		int aux1;
		for (aux1 = 0; aux1 < strlen(s_select->W.leftPredicate) - 2; aux1++) {
			s_select->W.leftPredicate[aux1] = s_select->W.leftPredicate[aux1 + 1];
		}
		s_select->W.leftPredicate[aux1] = '\0';
	}
	
	if (s_select->juncao && s_select->J.LPT == 'A') {
		int aux1;
		for (aux1 = 0; aux1 < strlen(s_select->J.leftPredicate) - 2; aux1++) {
			s_select->J.leftPredicate[aux1] = s_select->J.leftPredicate[aux1 + 1];
		}
		s_select->J.leftPredicate[aux1] = '\0';
	}
	
	if (s_select->selecao && s_select->W.RPT == 'A') {
		int aux1;
		for (aux1 = 0; aux1 < strlen(s_select->W.rightPredicate) - 2; aux1++) {
			s_select->W.rightPredicate[aux1] = s_select->W.rightPredicate[aux1 + 1];
		}
		s_select->W.rightPredicate[aux1] = '\0';
	}
	
	if (s_select->juncao && s_select->J.RPT == 'A') {
		int aux1;
		for (aux1 = 0; aux1 < strlen(s_select->J.rightPredicate) - 2; aux1++) {
			s_select->J.rightPredicate[aux1] = s_select->J.rightPredicate[aux1 + 1];
		}
		s_select->J.rightPredicate[aux1] = '\0';
	}
	
    tp_buffer *bufferpoll = initbuffer();

    if (bufferpoll == ERRO_DE_ALOCACAO) {
        free(bufferpoll);
        free(esquema);
        free(esquemaj);
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
            free(esquemaj);
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
			if (s_select->selecao) {
				if (s_select->W.LPT == 'I' || s_select->W.LPT == 'D' || s_select->W.LPT == 'S' || s_select->W.LPT == 'C' ||
					s_select->W.RPT == 'I' || s_select->W.RPT == 'D' || s_select->W.RPT == 'S' || s_select->W.RPT == 'C') {
					if (!verifyObjectWhere(s_select, pagina, i, objeto.qtdCampos)) {
						ntuples--;
						continue;
					}
				} else if (!verifySimpleWhere(s_select)) {
					ntuples--;
					continue;
				}
			}
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
    free(esquemaj);
}

int allColumnsExistsSelect(rc_select *s_select, tp_table *esquema, tp_table *esquemaj) {
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
			while (esquemaj != NULL) {
				if (strcmp(s_select->columnName[i], esquemaj->nome) == 0) {
					break;
				}
				esquemaj = esquemaj->next;
			}
			if (esquemaj == NULL) {
				printf("ERROR: column \"%s\" does not exist.\n", s_select->columnName[i]);
				return 0;
			}
		}
	}
	return 1;
}

void makeAllPredicates(rc_select *s_select, tp_table *esquema) {
	int i = 0;
	while (esquema != NULL) {
		s_select->columnName = realloc(s_select->columnName, (i + 1)*sizeof(char *));
		s_select->columnName[i] = malloc(sizeof(char)*(strlen(esquema->nome)+1));
		strcpy(s_select->columnName[i], esquema->nome);
		s_select->columnName[i][strlen(esquema->nome)] = '\0';
		esquema = esquema->next;
		i++;
	}
	s_select->N = i;
}

int existColumn(int O, int D, rc_select *s_select, tp_table *esquema, tp_table *esquemaj) {
	while (esquema != NULL) {
		if (O == 0) {
			if (D == 0) {
				if (strcmp(s_select->W.leftPredicate, esquema->nome) == 0) {
					s_select->W.LPT = esquema->tipo;
					break;
				}
			} else {
				if (strcmp(s_select->W.rightPredicate, esquema->nome) == 0) {
					s_select->W.RPT = esquema->tipo;
					break;
				}
			}
		} else {
			if (D == 0) {
				if (strcmp(s_select->J.leftPredicate, esquema->nome) == 0) {
					s_select->J.LPT = esquema->tipo;
					break;
				}
			} else {
				if (strcmp(s_select->J.rightPredicate, esquema->nome) == 0) {
					s_select->J.RPT = esquema->tipo;
					break;
				}
			}
		}
		esquema = esquema->next;
	}
	if (esquema == NULL) {
		while (esquemaj != NULL) {
			if (O == 0) {
				if (D == 0) {
					if (strcmp(s_select->W.leftPredicate, esquemaj->nome) == 0) {
						s_select->W.LPT = esquemaj->tipo;
						break;
					}
				} else {
					if (strcmp(s_select->W.rightPredicate, esquemaj->nome) == 0) {
						s_select->W.RPT = esquemaj->tipo;
						break;
					}
				}
			} else {
				if (D == 0) {
					if (strcmp(s_select->J.leftPredicate, esquemaj->nome) == 0) {
						s_select->J.LPT = esquemaj->tipo;
						break;
					}
				} else {
					if (strcmp(s_select->J.rightPredicate, esquemaj->nome) == 0) {
						s_select->J.RPT = esquemaj->tipo;
						break;
					}
				}
			}
			esquemaj = esquemaj->next;
		}
		if (esquemaj == NULL) {
			if (O == 0) {
				if (D ==0) printf("ERROR: column \"%s\" does not exist.\n", s_select->W.leftPredicate);
				else printf("ERROR: column \"%s\" does not exist.\n", s_select->W.rightPredicate);
			} else {
				if (D ==0) printf("ERROR: column \"%s\" does not exist.\n", s_select->J.leftPredicate);
				else printf("ERROR: column \"%s\" does not exist.\n", s_select->J.rightPredicate);
			}
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

int compatibleTypes(char t1, char t2, char *operator) {
	if (t1 == t2) return 1;
	if (t1 == 'D' && t2 == 'I') return 1;
	if (t1 == 'I' && t2 == 'D') return 1;
	if (t1 == 'S' && t2 == 'C' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'C' && t2 == 'S' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'C' && t2 == 'A' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'A' && t2 == 'C' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'S' && t2 == 'A' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'A' && t2 == 'S' && ( strcmp(operator, "=") == 0 || strcmp(operator, "<>") == 0 ) ) return 1;
	if (t1 == 'D' && t2 == 'V') return 1;
	if (t1 == 'V' && t2 == 'D') return 1;
	if (t1 == 'I' && t2 == 'V') return 1;
	if (t1 == 'V' && t2 == 'I') return 1;
	if (t1 == 'N' && t2 == 'V') return 1;
	if (t1 == 'V' && t2 == 'N') return 1;
	if (t1 == 'D' && t2 == 'N') return 1;
	if (t1 == 'N' && t2 == 'D') return 1;
	if (t1 == 'I' && t2 == 'N') return 1;
	if (t1 == 'N' && t2 == 'I') return 1;
	return 0;
}

int respectConditionN(double a, double b, char *condition) {
	if (strcmp(condition, "=") == 0) return !compDtoD(a, b);
	else if (strcmp(condition, "<>") == 0) return compDtoD(a, b);
	else if (strcmp(condition, "<") == 0) return a < b;
	else if (strcmp(condition, ">") == 0) return a > b;
	else if (strcmp(condition, ">=") == 0) return ((a > b) || (!compDtoD(a, b)));
	else if (strcmp(condition, "<=") == 0) return ((a < b) || (!compDtoD(a, b)));
	return 0;
}

int verifySimpleWhere(rc_select *s_select) {
	double a, b;
	if (s_select->W.LPT == 'N' || s_select->W.LPT == 'V') {
		a = atof(s_select->W.leftPredicate);
		b = atof(s_select->W.rightPredicate);
		return (respectConditionN(a, b, s_select->W.operator));
	}
	return ( !strcmp(s_select->W.leftPredicate, s_select->W.rightPredicate) && strcmp(s_select->W.operator, "=") == 0)
			|| ( strcmp(s_select->W.leftPredicate, s_select->W.rightPredicate) && strcmp(s_select->W.operator, "=") != 0);
}

int verifyObjectWhere(rc_select *s_select, column *pg, int i, int L) {
	
	int j, aux1, jj;
	double a, b;
	
	if (s_select->W.LPT == 'N' || s_select->W.LPT == 'V') {
		a = atof(s_select->W.leftPredicate);
		for (j=0; j < L; j++) {
			jj = j + (i * L);
			if (strcmp(pg[jj].nomeCampo, s_select->W.rightPredicate) == 0) {
				if (pg[jj].tipoCampo == 'I') {
					aux1 = *(int *) pg[jj].valorCampo;
					b = aux1;
				} else b = *(double *)pg[jj].valorCampo;
				break;
			}
		}
		return (respectConditionN(a, b, s_select->W.operator));
	}
	if (s_select->W.RPT == 'N' || s_select->W.RPT == 'V') {
		a = atof(s_select->W.rightPredicate);
		for (j=0; j < L; j++) {
			jj = j + (i * L);
			if (strcmp(pg[jj].nomeCampo, s_select->W.leftPredicate) == 0) {
				if (pg[jj].tipoCampo == 'I') {
					aux1 = *(int *) pg[jj].valorCampo;
					b = aux1;
				} else b = *(double *)pg[jj].valorCampo;
				break;
			}
		}
		return (respectConditionN(b, a, s_select->W.operator));
	}
	
	if (s_select->W.LPT == 'A') {
		for (j=0; j < L; j++) {
			jj = j + (i * L);
			if (strcmp(pg[jj].nomeCampo, s_select->W.rightPredicate) == 0) break;
		}
		return ( !strcmp(s_select->W.leftPredicate, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") == 0)
				|| ( strcmp(s_select->W.leftPredicate, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") != 0);
	}
	
	if (s_select->W.RPT == 'A') {
		for (j=0; j < L; j++) {
			jj = j + (i * L);
			if (strcmp(pg[jj].nomeCampo, s_select->W.leftPredicate) == 0) break;
		}
		return ( !strcmp(s_select->W.rightPredicate, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") == 0)
				|| ( strcmp(s_select->W.rightPredicate, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") != 0);
	}
	
	for (j=0; j < L; j++) {
		jj = j + (i * L);
		if (strcmp(pg[jj].nomeCampo, s_select->W.leftPredicate) == 0) {
			if (pg[jj].tipoCampo == 'I') {
				aux1 = *(int *) pg[jj].valorCampo;
				a = aux1;
				for (j=0; j < L; j++) {
					jj = j + (i * L);
					if (strcmp(pg[jj].nomeCampo, s_select->W.rightPredicate) == 0) {
						aux1 = *(int *) pg[jj].valorCampo;
						b = aux1;
						return (respectConditionN(a, b, s_select->W.operator));
					}
				}
			} else if (pg[jj].tipoCampo == 'D') {
				a = *(double *) pg[jj].valorCampo;
				for (j=0; j < L; j++) {
					jj = j + (i * L);
					if (strcmp(pg[jj].nomeCampo, s_select->W.rightPredicate) == 0) {
						b = *(double *) pg[jj].valorCampo;
						return (respectConditionN(a, b, s_select->W.operator));
					}
				}
			} else {
				int k = jj;
				for (j=0; j < L; j++) {
					jj = j + (i * L);
					if (strcmp(pg[jj].nomeCampo, s_select->W.rightPredicate) == 0) {
						return ( !strcmp(pg[k].valorCampo, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") == 0)
						|| ( strcmp(pg[k].valorCampo, pg[jj].valorCampo) && strcmp(s_select->W.operator, "=") != 0);
					}
				}
			}
		}
	}
	
	return 0;
}
