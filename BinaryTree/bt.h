/*
 * Binary tree head file
 */

typedef struct node {
	int	id;
	void	*data;
} NODE;

typedef struct bt {
	NODE	*node;
	struct bt	*left;
	struct bt	*right;
} BT;


