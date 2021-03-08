//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW6_¿úª³¥c_309706024.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int data;
int number;
int range;
String lin ="";
//«Å§i¾ð
struct BSTreeNode
{ struct BSTreeNode *leftchild;
  int data;
  struct BSTreeNode *rightchild;
 };
struct BSTreeNode *root;

//¤¤§Ç


struct BSTreeNode * NewBSTNode(int x)
{ struct BSTreeNode * node = new struct BSTreeNode;
//struct BSTreeNode *node=(struct BSTreeNode *)malloc(sizeof(struct BSTreeNod
  node->data = x;
  node->leftchild = NULL;
  node->rightchild = NULL;
  return node;
}
//insertbst
struct BSTreeNode * InsertBSTree(struct BSTreeNode * node, int x)
{if (node == NULL) return NewBSTNode(x);
  if (x < node->data){
   node->leftchild=InsertBSTree(node->leftchild,x);
  }
  else{
   node->rightchild=InsertBSTree(node->rightchild,x);
  }
  return node;
}

struct BSTreeNode *InorderSucc(struct BSTreeNode * node)
{ struct BSTreeNode * p = node;
  while (p->leftchild != NULL)
  p = p->leftchild;
  return p;
}
//delete
struct BSTreeNode * DeleteBSTree(struct BSTreeNode * node, int x)
{ struct BSTreeNode * temp;
  if (node == NULL) return node;
  if (x < node->data){
	node->leftchild = DeleteBSTree(node->leftchild, x);
  }
  else if (x > node->data){
	node->rightchild = DeleteBSTree(node->rightchild, x);
  }
  else // x found in node
  { if ((node->leftchild == NULL) || (node->rightchild == NULL))
	{ temp = node->leftchild ? node->leftchild:node->rightchild;
	if (temp == NULL) // node is a leaf itself
	 { temp = node;
	   node = NULL;
	 }
	else * node = * temp;
	free(temp);
  }
  else // node has two children
  { temp = InorderSucc(node->rightchild);
	node->data = temp->data;
	node->rightchild=DeleteBSTree(node->rightchild, temp->data);
  }
}
return node;
}


void inorder(struct BSTreeNode *node)
{ if (node != NULL)
  { inorder(node->leftchild);
	lin += IntToStr(node->data) + " --> ";
	//Form1 -> Memo1 -> Lines -> Add(IntToStr(node->data)+" --> ");
	inorder(node->rightchild);
  }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   root = NewBSTNode(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	data = Edit1 -> Text.ToInt();
	InsertBSTree(root,data);
	inorder(root);
	Form1 -> Memo1 -> Lines -> Add(" BST Inorder : "+lin+"<end");
	lin ="";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	data = Edit2 -> Text.ToInt();
	DeleteBSTree(root,data);
	inorder(root);
	Form1 -> Memo1 -> Lines -> Add(" BST Inorder : "+lin+"<end");
	lin ="";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	Memo2 -> Text = TrackBar1 -> Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
	Memo3 -> Text = TrackBar2 -> Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	number = Memo2 -> Text.ToInt();
	range = Memo3 -> Text.ToInt();
	String line ="";
	for (int i = 0; i < number; i++) {
	   data = rand() % range + 1;
	   line += IntToStr(data) + "---";
	   InsertBSTree(root,data);
	}
	Form1 -> Memo1 -> Lines -> Add(IntToStr(number)+" random number : "+line+"end");
	inorder(root);
	Form1 -> Memo1 -> Lines -> Add(" BST Inorder : "+lin+"<end");
	lin ="";

}
//---------------------------------------------------------------------------

