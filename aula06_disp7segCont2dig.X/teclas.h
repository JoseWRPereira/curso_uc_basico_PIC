/* 
 * File:   teclas.h
 * Author: josewrpereira
 *
 * Created on 4 de Outubro de 2021, 22:34
 */

#ifndef TECLAS_H
#define	TECLAS_H

void teclas_init( void );

char tecla_incrementar( void );
char tecla_incrementar_borda_subida( void );
char tecla_incrementar_borda_descida( void );

char tecla_decrementar( void );
char tecla_decrementar_borda_subida( void );
char tecla_decrementar_borda_descida( void );

#endif	/* TECLAS_H */

