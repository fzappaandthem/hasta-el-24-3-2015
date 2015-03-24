/*
 * main.c
 *
 *  Created on: 24/3/2015
 *      Author: utnso
 *
 *
 */

#include <stdio.h>

#define W_AS_TABS 4

#define MAXLINE 1000

int get_indented_line ( char line [] );
int replace_tabs ( char tab [], int len );
int next_tab_stop (int i);

int main ( void )
{
	int len = 0 ;
	char line [MAXLINE] ;

	while ( len >= 0 )
	{
		len = get_indented_line ( line );
		if ( len != 0 )//not an empty line
			printf ("%s\n", line);//if you got a full line, show it ...!
	}
	return 0;
}

int get_indented_line ( char line [] )
{
	int c, i;
	i = 0;
	while ( ( c = getchar () ) != EOF && c != '\n' && i < MAXLINE-1 )
	{
		if ( c == '\t' )
			i = replace_tabs ( line , i );
		else
		{
			line [i] = c;
			++ i;
		}
	}
	line [i] = '\0';
	if ( c == EOF )
		return -1;
	return i;
}

int replace_tabs ( char s [], int len )
{
	int lim = next_tab_stop ( len );
	while ( len <= lim && len < MAXLINE-1 )
	{
		s [len] = 32;
		++len;
	}
	return len ;
}

int next_tab_stop ( int i)
{
	++ i; //I need next tab stop, so if len is a "tab stop position" I force the function to find the next one
	while ( i % W_AS_TABS > 0 )
		++i;
	return i;
}
