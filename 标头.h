typedef struct stu
{
	unsigned long long num;  //学号
	char name[9];    //   字符串结束符 勿忘 ！！！
	int sex;     //性别
	unsigned int age;
	char major[15];    //专业

}student;
typedef struct node
{
	DataType data;      //  #define DataType student
	struct node* leftson;
	struct node* rightson;
}shu;
int zhao(shu* root, unsigned long long x);
//int cha(shu** root, DataType x);
int shanshu(shu** root, unsigned long long x);
int shanshugen(shu** root, unsigned long long x);
shu* minshu(shu* root);
shu* maxshu(shu* root);

int getmax(int a, int b)  //比较大小，返回较大值
{
	if (a >= b)
		return a;
	else
		return b;
}
int gaodu(shu* root)     // 求该节点的高度
{
	if (root == 0)
		return -1;
	return (getmax(gaodu(root->leftson), gaodu(root->rightson)) + 1);
}
shu* ll(shu* p)      //     左左  
{
	shu* t = p->leftson;
	if (t != 0)     // lr 时只需 rr 
	{
		p->leftson = t->rightson;
		t->rightson = p;
	}
	else
	{

	}
	return t;
}

shu* rr(shu* p)        //   右右
{
	shu* t = p->rightson;
	if (t != 0)
	{
		p->rightson = t->leftson;
		t->leftson = p;
	}
	else
	{

	}
	return t;
}
shu* lr(shu* p)            //    左右          //  网上都是rl
{
	p->rightson = ll(p->rightson);
	shu* t = rr(p);
	return t;
}
shu* rl(shu* p)            //    右左
{

	p->leftson = rr(p->leftson);
	shu* t = ll(p);
	return t;
}
int chaping(shu** root, DataType x)       //  二叉  平衡  树的插入  递归    插入成功返回1，失败返回0
{

	if (*root == 0)
	{
		(*root) = (shu*)malloc(sizeof(shu));
		(*root)->data = x;
		(*root)->leftson = (*root)->rightson = 0;
	}
	else
		if (x.num  < (*root)->data.num )   //  进入左子树
		{
			chaping(&((*root)->leftson), x);
			if (gaodu((*root)->leftson) - gaodu((*root)->rightson) == 2)   //     判断二叉树是否   失衡  (因插入)
																		   //      此 if 语句可用于使失衡的二叉树平衡
			{
				if (gaodu((*root)->leftson->leftson) >= gaodu((*root)->leftson->rightson))
				{                                                           // == 在因插入失衡看来，不可能出现==情况
					*root = ll(*root);
				}
				else
					*root = rl(*root);    //注意本程序 rl 与网上 lr 内容一致 ,名字相反
			}
		}
		else
			if (x .num > (*root)->data.num )   //  进入右子树
			{
				chaping(&((*root)->rightson), x);
				if (gaodu((*root)->leftson) - gaodu((*root)->rightson) == -2)
				{
					if (gaodu((*root)->rightson ->leftson) <= gaodu((*root)->rightson ->rightson))
						*root = rr(*root);
					else
						*root = lr(*root);
				}
			}
			else                        //==  树中已有该关键字，插入失败
			{
	     		return 0;
			}
	return 1;
}
int shanping(shu** root, unsigned long long  x)      //  二叉  平衡  树的删除（结点）    删除成功返回1，失败返回0
{
	if (root == 0)                         //  说明 树中 无 该关键字  对树不进行任何操作
		return 0;
	else
		if (x  < (*root)->data.num )   //  进入左子树
		{
			shanping(&((*root)->leftson), x);
			if (gaodu((*root)->leftson) - gaodu((*root)->rightson) == -2)   //     判断二叉树是否   失衡  (因删除)
			{														   //      此 if 语句可用于使失衡的二叉树平衡

				if (gaodu((*root)->rightson->leftson) <= gaodu((*root)->rightson->rightson))
				{                                                          //==在因删除失衡看来,可以出现==情况
					*root = rr(*root);
				}
				else
					*root = lr(*root);                                     //注意本程序 rl 与网上 lr 内容一致 ,名字相反
			}
		}
		else
			if (x  > (*root)->data.num )   //  进入右子树
			{
				shanping(&((*root)->rightson), x);
				if (gaodu((*root)->leftson) - gaodu((*root)->rightson) == 2)
				{

					if (gaodu((*root)->leftson->leftson) >= gaodu((*root)->leftson->rightson))
						*root = ll(*root);
					else
						*root = rl(*root);
				}
			}
			else                        //==  树中找到该关键字，开始删除
			{
				shanshu(root, x );        // 不用担心效率，root是当前找到的结点，可以说在shanshu函数 一开始就会找到
			}
	return 1;
}
int zhao(shu* root, unsigned long long x)   // 二叉  排序  树的查找，循环方法   找到返回1,没找到或空树 返回0
{
	if (root == 0)
	{

		return 0;
	}

	shu* p = root;
	while (p != 0)
	{
		if (p->data.num == x)
		{
			//cout<<p->data .num 
			printf("学号%lld     姓名%s    性别", p->data.num, p->data.name);
			if (p->data.sex == 0)
				cout << "女";
			else
				cout << "男";


			printf("      年龄%d    专业%s\n", p->data.age, p->data.major);
			return 1;
		}
		if (p->data.num > x)
			p = p->leftson;
		else
			p = p->rightson;
	}
	return 0;
}

int shanshugen(shu** root, unsigned long long x)   // 专门用于二叉排序树的  根结点  的删除  因为删除根节点，需要改变*root
{
	shu* p = (*root);
	if (p->data.num != x)
	{
		cout << "根节点的值与所找的结点值不同";
		return 0;
	}
	if (p->leftson == 0 && p->rightson == 0)          //被删除结点  无孩子结点
	{
		free(p);
		(*root) = 0;
	}
	else if (p->leftson != 0 && p->rightson == 0)      //被删除结点只有  左孩子结点
	{
		(*root) = p->leftson;
		free(p);
	}
	else if (p->leftson == 0 && p->rightson != 0)      //被删除结点只有  右孩子结点
	{
		(*root) = p->rightson;
		free(p);
	}
	else                                               //被删除结点 左右孩子结点  都有  
	{
		shu* curr = p;                  // 以下代码  1均复制粘贴于 shanshu 函数的被删除结点 左右孩子结点 都有的情况代码
										 //         2下面两种情况均不会删除 二叉树本身的根结点 也就是说  *(*root)不用改变
		if (curr->rightson->leftson == 0)
		{
			shu* q = curr->rightson;
			curr->data = curr->rightson->data;
			curr->rightson = curr->rightson->rightson;
			free(q);
		}
		else
		{
			curr->data = curr->rightson->leftson->data;
			shanshu(&curr->rightson, curr->data.num);
		}
	}
	return 1;
}
int shanshu(shu** root, unsigned long long x)  //  二叉  排序  树的删除（结点）  空树或未找到该结点return 0   找到该结点并删除return 1
{
	int tag = 0;
	shu* curr = *root;
	shu* parent = 0;
	while (curr != 0)
	{
		if (curr->data.num == x)
		{
			tag = 1;        //说明找到了 应被删除的结点
			break;
		}

		parent = curr;

		if (curr->data.num > x)
			curr = curr->leftson;
		else
			curr = curr->rightson;
	}
	if (tag == 0)
		return 0;


	if (parent == 0)  //被删除的结点是  根结点  
	{
		shanshugen(root, x);    // 调用专门删除 根节点 函数
	}
	else
	{
		if (curr->leftson == 0 && curr->rightson == 0)  //被删除结点  无孩子结点  //警告没用
		{
			if (parent->leftson == curr)
			{
				parent->leftson = 0;
			}
			else
				parent->rightson = 0;

			free(curr);

		}
		else
			if (curr->leftson != 0 && curr->rightson == 0)   //被删除结点只有  左孩子结点
			{
				if (parent->leftson == curr)
				{
					parent->leftson = curr->leftson;
				}
				else
					parent->rightson = curr->leftson;

				free(curr);
			}
			else
				if (curr->leftson == 0 && curr->rightson != 0)   //被删除结点只有  右孩子结点
				{
					if (parent->leftson == curr)
					{
						parent->leftson = curr->rightson;
					}
					else
						parent->rightson = curr->rightson;

					free(curr);
				}
				else                                               //被删除结点  左右孩子结点都有
				{
					if (gaodu(curr->rightson) - gaodu(curr->leftson) >= 0)  //右子树高度 > =左子树  这样可以尽可能的使二叉树平衡
					{
						shu* w = minshu(curr->rightson);
						curr->data = w->data;
						shanshu(&w, w->data.num);
					}
					else                                                   //  右子树高度 <  左子树
					{
						shu* w = maxshu(curr->leftson);
						curr->data = w->data;
						shanshu(&w, w->data.num);
					}
					/*if (curr->rightson->leftson == 0)   //  课本way   有风险
					{
						shu* q = curr->rightson;
						curr->data = curr->rightson->data;
						curr->rightson = curr->rightson->rightson;
						free(q);
					}
					else
					{
						curr->data = curr->rightson->leftson->data;
						shanshu(&curr->rightson, curr->data.num);
					}
					*/

				}
	}
	return 1;
}
shu* minshu(shu* root)              //  求该二叉排序树的最  小  值结点,返回结点地址
{
	shu* p = root;
	if (root == 0)
	{
		cout << "空树无最小结点" << endl;
		return 0;
	}
	while (p->leftson != 0)
	{
		p = p->leftson;
	}
	return p;
}
shu* maxshu(shu* root)             //     求该二叉排序树的最  大   值结点,返回结点地址
{
	shu* p = root;
	if (root == 0)
	{
		cout << "空树无最大结点" << endl;
		return 0;
	}
	while (p->rightson != 0)
	{
		p = p->rightson;
	}
	return p;
}
int qianxusum(shu* q)  //计算二叉树的结点总数
{
	int sum = 0;
	if (q != 0)
	{
		sum += 1;
		sum += (qianxusum(q->leftson) + qianxusum(q->rightson));

	}
	return sum;

}
int xiaohui(shu** p)       //二叉树的销毁
{
	if (p == 0)
	{
		cout << "当前结点为空，无法销毁" << endl;
		return -1;
	}
	if ((*p)->leftson != 0)
	{
		xiaohui(&(*p)->leftson);

	}
	if ((*p)->rightson != 0)
	{

		xiaohui(&(*p)->rightson);
	}
	free(*p);
	*p = 0;
	return 1;
}
void wen(shu* x)
{
	printf("%d  ", x->data);
}
void dayin(shu* q, int n)
{

	if (q != 0)
	{
		n++;
		dayin(q->rightson, n);
		for (int i = 0; i < n; i++)
			printf("  ");
		wen(q);
		printf("\n");
		dayin(q->leftson, n);


	}

}
