#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char Name[20];                   //姓名
    char Gender;                       //性别 
    int  Num;                        //儿女个数 
    
    struct TreeNode * NextNode[20];  //记录这个人的儿女
    struct TreeNode * Parent;        //记录这个节点的父节点
}TreeNode;
int k=0;
void CreatTree(TreeNode *Tree);
void OutPutAll(TreeNode *Tree);
TreeNode *  SearchTree(TreeNode *Tree,char name[],int length);
void MainMenue(TreeNode *Tree);
void SubMenue1(TreeNode * Tree);
void SubMenue2(TreeNode *Tree);
void Change(TreeNode * Tree);
void AddNew(TreeNode * Tree);
void OutPutMessage(TreeNode * Tree,char name[],int length);//输出已经查找到的人的信息

//主函数
int main()
{
    TreeNode *Tree;
    Tree=(TreeNode *)malloc(sizeof(TreeNode));
    Tree->Parent =NULL;
    strcpy(Tree->Name,"0");
    MainMenue(Tree);
}
//添加新的成员
void AddNew(TreeNode * Tree)
{
    SubMenue2(Tree);
}
//输出副菜单
void SubMenue2(TreeNode *Tree)
{
    char c;
    int  num;
    char name[20];
    TreeNode * NewNode;
    
    getchar();
    while(1)
    {
        system("cls");
        printf("\t");
        printf("\n\n\t           ---*****---请选择你的操作---****---                 ");
        printf("\n\t---*---*---*---A:添加某个人的子女的信息---*---*---*---*----    ");
        printf("\n\t---*---*---*---B:添加某个人配偶的信息-*---*---*---*---*----    ");
        printf("\n\t---*---*---*---C:退出-*---*---*---*---*---*---*---*---*----\n\t");
        
        c=getchar();
        switch(c)
        {
        case 'A':
          printf("\n\n\t请输入那个人的名字:\n\t");
            scanf("%s",name);
            Tree=SearchTree(Tree,name,20);
            if(Tree==NULL)
            {
                printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n",name);
                break;
            }
            if(Tree->Parent==NULL&&Tree->NextNode[0]==NULL||Tree->Parent!=NULL&&Tree->Name!=Tree->Parent->NextNode[0]->Name)
            {
                printf("\n\n\t%s至今还没有配偶请先添加配偶",Tree->Name);
                break;
            }
            if(Tree->Parent==NULL&&(Tree->Num>20||Tree->Num<0))
                Tree->Num=0;
            if(k==1)
              Tree=Tree->Parent;
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\n\t请输入添加人员姓名:\n\t");
            scanf("%s",NewNode->Name);
            printf("\n\n\t请输入添加人员性别女G男B:\n\t");
            scanf("%1s",&NewNode->Gender);
            num=Tree->Num;
            NewNode->NextNode[0]=(TreeNode *)malloc(sizeof(TreeNode));
            NewNode->NextNode[0]=NULL;
            NewNode->Num=0;
            NewNode->Parent=Tree;
            Tree->NextNode[num+1]=NewNode;
            Tree->Num=Tree->Num+1;
             printf("\n\n\t-------------子女的信息添加成功----------------");
            break;
        case 'B':
          printf("\n\n\t请输入那个人的名字:\n\t");
            scanf("%s",name);
            Tree=SearchTree(Tree,name,20);
            if(Tree->Parent!=NULL&&strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0||Tree->NextNode[0]!=NULL)
            {
                printf("\n\n\t已经有了配偶");
                break;
            }
            if(Tree==NULL)
            {
                printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n",name);
                break;
            }
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\n\t请输入添加人员姓名:\n\t");
            scanf("%s",NewNode->Name);
            printf("\n\n\t请输入添加人员性别女G男B:\n\t");
            scanf("%1s",&NewNode->Gender);
            NewNode->Parent=Tree;
            Tree->NextNode[0]=NewNode;
            break;
        case 'C':    
          printf("\n\n\t----------------本项服务到此结束-----------------");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------对不起!你的选择不在服务范围之内!---------    ");
            printf("\n\t-----------请您再次选择所需的服务项!-------------    ");
            printf("\n\t------------------谢谢合作!----------------------\n\t");
            break;
        }
        if (c=='C'||c=='c')
            break;
          printf("\n\n\t--------------请按Enter键继续操作--------------");
        getchar();
        getchar();
    }
}
//修改某个人的信息
void Change(TreeNode * Tree)
{
    char name[20];
    TreeNode * NewNode;
    printf("\n\t请输入你要修改的人的信息:\n\t");
    scanf("%s",name);
  
    NewNode=SearchTree(Tree,name,20);
    if(NewNode==NULL)
    {
        printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n",name);
        return;
    }
    else 
    {
        SubMenue1(NewNode);
    }
}

//输出副菜单
void SubMenue1(TreeNode * Tree)
{
    char c;
    int  flag,i;
    char name[20];
    char Parent[2][20];
    TreeNode * NewNode;
    getchar();
    while(1)
    {
        system("cls");
        printf("\t");
        printf("\n\n\t           ---*****---请选择你的操作---****---                 ");
        printf("\n\t---*---*---*---1:修改个人的信息---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---2:修改父母的信息---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---3:修改兄弟姐妹的信息---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---4:修改子女的信息---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---5:修改配偶的信息---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---6:退出-*---*---*---*---*---*---*---*---*----\n\t");
        
        c=getchar();
        switch(c)
        {
        case 'A':
            printf("\n\n\t请输入修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t");
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
               strcpy(Tree->Name,name);
            printf("\n\n\t是否要修改性别:如果需要就输入'1'不需要修改就输入'0'然后按Enter键继续\n\t");
            scanf("%d",&flag);
            if (flag==1)
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                    Tree->Gender='B';
                else Tree->Gender='G';
            }
            printf("\n\n\t个人信息修改成功");
            break;
        case 'B':
            if(Tree->Parent==NULL)                                         //判断是不是头节点
            {
                printf("\n\t是这个家谱图里最顶端的人没有父母信息!",name);
                break;
            }
            if (k==1)                                             //判断是不是入赘或加入此间的
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                {  
                    printf("\n\n\t她是嫁入此间的所以父母信息不在家谱内包括");
                }
                else
                {
                    printf("\n\n\t他是入赘此间的所以父母信息不在家谱内包括");
                }
                break;
            }
            if(Tree->Parent->Gender=='G'||Tree->Parent->Gender=='g')
            {
                strcpy(Parent[0],"母亲");
                strcpy(Parent[1],"父亲");
            }
            else 
            {
                strcpy(Parent[0],"父亲");
                strcpy(Parent[1],"母亲");
            }
            
            printf("\n\n\t请输入%s要修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Parent[0]);
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
                strcpy(Tree->Parent->Name,name);
            printf("\n\n\t请输入%s要修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Parent[1]);
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
                strcpy(Tree->Parent->NextNode[0]->Name,name);
            printf("\n\n\t-------------父母的信息修改成功----------------");
            break;
        case 'C':
            NewNode=Tree->Parent;
            if(NewNode==NULL)                                         //判断是不是头节点
            {
                printf("\n\t是这个家谱图里最顶端的人没有兄弟姐妹信息!",name);
                break;
            }
            if (k==1)                                             //判断是不是入赘或加入此间的
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                {  
                    printf("\n\n\t她是嫁入此间的所以兄弟姐妹信息不在家谱内包括");
                }
                else
                {
                    printf("\n\n\t他是入赘此间的所以兄弟姐妹信息不在家谱内包括");
                }
                break;
            }
            if(NewNode->Num==1)
            {
                printf("\n\n\t没有兄弟姐妹");
                break;
            }
            else
            {
                for(i=1;i<=NewNode->Num;i++)
                {
                    if(NewNode->NextNode[i]->Name!=Tree->Name)
                    {
                        printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",NewNode->NextNode[i]->Name);
                        scanf("%s",name);
                        if(strcmp(name,"0")!=0)
                            strcpy(NewNode->NextNode[i]->Name,name);
                        
                        printf("\n\n\t是否要修改性别:如果需要就输入'1'不需要修改就输入'0'然后按Enter键继续\n\t");
                        scanf("%d",&flag);
                        if (flag==1)
                        {
                            if(NewNode->NextNode[i]->Gender=='G'||NewNode->NextNode[i]->Gender=='g')
                                NewNode->NextNode[i]->Gender='B';
                            else NewNode->NextNode[i]->Gender='G';
                        }
                    }
                }
            }
          printf("\n\n\t------------兄弟姐妹的信息修改成功-------------");
            break;
        case 'D':
            if(Tree->Num==0)
            {
                printf("\n\n\t至今还没有子女");
                break;
            }
            if (Tree->Parent !=NULL)
                if (strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0)       //如果他是入赘或者是嫁入的就需用配偶节点完成修改
                {
                    Tree=Tree->Parent;
                }
            for(i=1;i<=Tree->Num;i++)
            {        
                printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Tree->NextNode[i]->Name);
                scanf("%s",name);
                if(strcmp(name,"0")!=0)
                    strcpy(Tree->NextNode[i]->Name,name);
                
                printf("\n\n\t是否要修改性别:如果需要就输入'1'不需要修改就输入'0'然后按Enter键继续\n\t");
                scanf("%d",&flag);
                if (flag==1)
                {
                    if(Tree->NextNode[i]->Gender=='G'||Tree->NextNode[i]->Gender=='g')
                        Tree->NextNode[i]->Gender='B';
                    else Tree->NextNode[i]->Gender='G';
                }
                
            }
          printf("\n\n\t---------------子女的信息修改成功----------------");
            break;
        case 'E':
            if(Tree->Parent!=NULL)
            {
                if (Tree->NextNode[0]==NULL&&strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)!=0)
                {
                    printf("\n\n\t至今还没有配偶");
                    break;
                }
                
                if (strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0)
                {
                    printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Tree->Parent->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->Parent->Name,name);        
                }
                else
                {
                    printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Tree->NextNode[0]->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->NextNode[0]->Name,name);
                }
            }
            else
            {
                if(Tree->NextNode[0]==NULL)
                    printf("\n\n\t至今还没有配偶");
                else
                {
                    printf("\n\n\t请输入%s修改的姓名:如果不需要修改就输入‘0’然后按Enter键继续\n\t",Tree->NextNode[0]->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->NextNode[0]->Name,name);
                }
            }
          printf("\n\n\t---------------配偶的信息修改成功----------------");
            break;
        case 'F':
          printf("\n\n\t----------------本项服务到此结束-----------------");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------对不起!你的选择不在服务范围之内!---------");
            printf("\n\t-----------请您再次选择所需的服务项!-------------");
            printf("\n\t------------------谢谢合作!----------------------\n\t");
            break;
        }
        if (c=='F'||c=='f')
            break;
          printf("\n\n\t--------------请按Enter键继续操作--------------");
        getchar();
        getchar();
    }
}
//输出主菜单
void MainMenue(TreeNode *Tree)
{
    char c;
    char name[20];
    while(1)
    {
        system("cls");
        printf("\t");
        printf("\n\n\t         ---*****---请选择你的操作---****---");
        printf("\n\t--------------1:输入家谱信息建立多叉树----------------------");
        printf("\n\t--------------2:在家族中查找某人并输出相应信息--------------");
        printf("\n\t--------------3:添加新的成员--------------------------------");
        printf("\n\t--------------4:输出整个家谱信息----------------------------");
        printf("\n\t--------------5:修改某个人的信息----------------------------");
        printf("\n\t--------------6:退出整个程序--------------------------------\n\t");
        
        c=getchar();
        switch(c)
        {
        case '1':
            TreeNode * NewNode;
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\t请输入姓名:\n\t");
            scanf("%s",Tree->Name);
            printf("\n\t请输入性别女G男B:\n\t");
            getchar();
            scanf("%c",&(Tree->Gender));
            Tree->Parent=NewNode;
            Tree->Parent=NULL;
            CreatTree(Tree);
            printf("\n\t--------------家谱图已经建立成功---------------\n\n");
            printf("\n\n\t--------------请按Enter键继续操作--------------");
            getchar();
            break;
        case '2':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
                getchar();
                break;
            }
            printf("\n\t请输入你要查找的人的姓名:\n\t");
            scanf("%s",name);
            OutPutMessage(SearchTree(Tree,name,20),name,20);
            printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
            getchar();
            break;
        case '3':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
                getchar();
                break;
            }
            AddNew(Tree);
            getchar();
            break;
        case '4':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
                getchar();
                break;
            }
            printf("\n\n\t整个家谱的主要信息如下:");
            OutPutAll(Tree);
            getchar();
            break;
        case '5':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t家谱图的多叉树尚未建立请先建立树\n");
                getchar();
                break;
            }
            Change(Tree);
            getchar();
            break;
        case '6':
          printf("\n\n\t-----------------本次服务到此结束------------------");
            printf("\n\t------------------欢迎下次使用---------------------");
            printf("\n\t----------------------谢谢-------------------------\n\n");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------对不起!你的选择不在服务范围之内!-----------");
            printf("\n\t-----------请您再次选择所需的服务项!---------------");
            printf("\n\t------------------谢谢合作!------------------------\n\t");
            getchar();
            break;
        }
        if (c==6)
            break;
        
        getchar();
    }
}
//创建树
void CreatTree(TreeNode *Node)
{
    int i;
    TreeNode *NewNode;
    NewNode=(TreeNode *)malloc(sizeof(TreeNode));
    Node->NextNode[0]=NewNode;
    Node->NextNode[0]=NULL;
    //Node->Parent =NULL;
    printf("\n\t请输入%s的子女的数目:\n\t",Node->Name);
    scanf("%d",&(Node->Num));
    printf("\n\t请输入%s的配偶的姓名:\n\t",Node->Name);
    scanf("%s",NewNode->Name);
    if((Node->Num)==0&&strcmp(NewNode->Name,"0")==0)
        return ;
    if (Node->Gender=='G'||Node->Gender=='g')
        NewNode->Gender='B';
    else 
        NewNode->Gender='G';
    NewNode->Num=0;
    NewNode->NextNode[0]=NULL;
    Node->NextNode[0]=NewNode;
    Node->NextNode[0]->Parent=Node;
    for(i=1;i<=Node->Num;i++)
    {
        NewNode=(TreeNode *)malloc(sizeof(TreeNode));
        printf("\n\t请输入%s的第%d子女的名字\n\t",Node->Name,i);
        scanf("%s",NewNode->Name);
        printf("\n\t请输入%s的第%d子女的性别女G男B:\n\t",Node->Name,i);
        getchar();
        scanf("%c",&NewNode->Gender);
        NewNode->Num=0;
        NewNode->Parent=Node;
        Node->NextNode[i]=NewNode;
        CreatTree(Node->NextNode[i]);
    }
}
//遍历并输出树中的内容
void OutPutAll(TreeNode *Tree)
{
    int i, flag=0;
    printf("\n\t---****---***---***---***---***---***---***---***---***---");
    printf("\n\t姓名:%s 性别:",Tree->Name);
    if (Tree->Gender=='G'||Tree->Gender=='g')
    {
        flag=1;
        printf("女");
    }
    else 
        printf("男");
    if (!(Tree->NextNode[0]))
    { 
        printf("\n\t至今没有配偶和子女\n");
        return;
    }
    if(flag==1)
        printf("\n\t丈夫 姓名:%s",Tree->NextNode[0]->Name);
    else
        printf("\n\t妻子 姓名:%s",Tree->NextNode[0]->Name);
    for(i=1;i<=Tree->Num;i++)
    {
        printf("\n\t第%d个子女的姓名:%s 性别:",i,Tree->NextNode[i]->Name,Tree->NextNode[i]->Gender);
        if (Tree->NextNode[i]->Gender=='G'||Tree->NextNode[i]->Gender=='g')
            printf("女");
        else 
            printf("男");
    }
    printf("\n\t");
    for(i=1;i<=Tree->Num;i++)
    {
        OutPutAll(Tree->NextNode[i]);
    }
}
//在树中经过遍历查找某个人
TreeNode * SearchTree(TreeNode *Tree,char name[],int length)
{
    int i;
    TreeNode *NewNode;
       if(strcmp(Tree->Name,name)==0)
    {
        if(length==0)
              k=1;
        else 
              k=0;
        return Tree;
    }
    if(Tree->NextNode[0]==NULL)
        return NULL;
    for(i=0;i<=Tree->Num;i++)
    {
        if (i==0)
          NewNode=SearchTree(Tree->NextNode[i],name,0);
              
        else 
          NewNode=SearchTree(Tree->NextNode[i],name,20);
        if (NewNode!=NULL)
          return NewNode;     
    }    
    return NULL;
}
//输出已经查找到的人的信息
void OutPutMessage(TreeNode * Tree,char name[],int length)
{
        int flag=0,i;
        TreeNode *NewNode;
            printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----");
        if(Tree==NULL)
        {
            printf("\n\n\t****该家谱图中没有%s这个人的信息请确认是否输入错误*****\n",name);
            return;
        }
        printf("\n\n\t您所要找的人已经找到信息如下所示:");
        printf("\n\n\t姓名:%s\t性别:",name);
    
        if (Tree->Gender=='G'||Tree->Gender=='g')
        { 
            flag=1;                                         //标记成员性别
            printf("女");
        }
        else 
            printf("男");
        NewNode=Tree->Parent;
        if (k==1)
        {
            
            if(flag==1)
            {  
                printf("\n\n\t她是嫁入此间的所以父母信息不在家谱内包括");
                printf("\n\t丈夫 姓名:%s",NewNode->Name);
            }
            else
            {
                printf("\n\n\t他是入赘此间的所以父母信息不在家谱内包括");
                printf("\n\t妻子 姓名:%s",NewNode->Name);
            }
            if ((NewNode->Num)>0)                                //判断成员否有孩子
            {        
                printf("\n\t的孩子的信息如下:");               //输出成员的孩子的信息
                for(i=1;i<=NewNode->Num;i++)
                {
                    printf("\n\t姓名:%s  性别:",NewNode->NextNode[i]->Name);
                    
                    if (NewNode->NextNode[i]->Gender=='G'||NewNode->Gender=='g') 
                        printf("女");
                    else 
                        printf("男");
                }
            }
            return;
        }
                              
        if(NewNode==NULL)                                    //判断它是不是根节点如果是的话就没有父母兄弟信息
            printf("\n\t是这个家谱图里最顶端的人没有父母和兄弟姐妹信息!",name);
        else
        {
            if (NewNode->Gender=='G'||NewNode->Gender=='g')      //判断父亲节点是父亲还是母亲
            {                                                 //输出他（她）的父母亲的信息
                printf("\n\t母亲 姓名:%s",NewNode->Name);
                printf("\n\t父亲 姓名:%s",NewNode->NextNode[0]->Name);
            }
            else 
            {
                printf("\n\t母亲 姓名:%s",NewNode->NextNode[0]->Name);
                printf("\n\t父亲 姓名:%s",NewNode->Name);
            }
            if (NewNode->Num>1)                             //判断他(她)是否有兄弟姐妹
            {                                                //输出他(她)的兄弟姐妹的信息
                printf("\n\t%s的兄弟姐妹信息如下:",name);                                            
                for(i=1;i<=NewNode->Num;i++)
                {
                    if(NewNode->NextNode[i])
                        printf("\n\t%s姓名:%s  性别:",NewNode->NextNode[i]->Name,NewNode->NextNode[i]->Name);
                    
                    if (NewNode->NextNode[i]->Gender=='G'||Tree->Gender=='g')
                        printf("女");
                    else 
                        printf("男");
                }
            }
            else
                printf("\n\t%s没有兄弟姐妹!",Tree->Name);
        }
        if(Tree->NextNode[0]!=NULL)                         //判断他(她)是否有配偶
        {                                                //输出他(她)的配偶的信息
            if(flag==1)
                printf("\n\t丈夫 姓名:%s",Tree->NextNode[0]->Name);
            else
                printf("\n\t妻子 姓名:%s",Tree->NextNode[0]->Name);
            if (Tree->Num>0)                             //判断他(她)是否有孩子
            {        
                printf("\n\t的孩子的信息如下:");       //输出他(她)的孩子的信息
                for(i=1;i<=Tree->Num;i++)
                {
                    printf("\n\t姓名:%s  性别:",Tree->NextNode[i]->Name);
                    
                    if (Tree->NextNode[i]->Gender=='G'||Tree->Gender=='g') 
                        printf("女");
                    else 
                        printf("男");
                }
            }
            else
                printf("\n\t%s至今还没有孩子",name);
        }
        else 
            printf("\n\t%s至今还没有配偶和孩子\n",Tree->Name);    
}

