/*
 * determine if someone wins in a tic tac game
 * 2/1/2017
 */
#include <stdio.h>
#include <stdbool.h>

#define	TIC	1
#define	TAC	2

int game[3][3] ={{TIC, TAC, TIC},
		{TIC, TAC, TAC},
		{TAC, 0, TIC}};

bool
tic_tac_win(int tic)
{
	int	k;

	/* check rows */
	for(k=0; k < 3; k++)
		if (game[k][0] == tic &&
			game[k][1] == tic &&
			game[k][2] == tic )
			return	true;

	/* check columns */
	for(k=0; k < 3; k++)
		if (game[0][k] == tic &&
			game[1][k] == tic &&
			game[2][k] == tic )
			return	true;

	/* check diag lines */
	if (game[0][0] == tic &&
		game[1][1] == tic &&
		game[2][2] == tic )
			return	true;

	if (game[0][2] == tic &&
		game[1][1] == tic &&
		game[2][0] == tic )
			return	true;

	return	false;
}


main()
{
	printf("win by tic: %s\n", tic_tac_win(TIC) ? "true": "false");
	printf("win by tac: %s\n", tic_tac_win(TAC) ? "true": "false");
}
