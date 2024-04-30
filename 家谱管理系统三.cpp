#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char Name[20];                   //����
    char Gender;                       //�Ա� 
    int  Num;                        //��Ů���� 
    
    struct TreeNode * NextNode[20];  //��¼����˵Ķ�Ů
    struct TreeNode * Parent;        //��¼����ڵ�ĸ��ڵ�
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
void OutPutMessage(TreeNode * Tree,char name[],int length);//����Ѿ����ҵ����˵���Ϣ

//������
int main()
{
    TreeNode *Tree;
    Tree=(TreeNode *)malloc(sizeof(TreeNode));
    Tree->Parent =NULL;
    strcpy(Tree->Name,"0");
    MainMenue(Tree);
}
//����µĳ�Ա
void AddNew(TreeNode * Tree)
{
    SubMenue2(Tree);
}
//������˵�
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
        printf("\n\n\t           ---*****---��ѡ����Ĳ���---****---                 ");
        printf("\n\t---*---*---*---A:���ĳ���˵���Ů����Ϣ---*---*---*---*----    ");
        printf("\n\t---*---*---*---B:���ĳ������ż����Ϣ-*---*---*---*---*----    ");
        printf("\n\t---*---*---*---C:�˳�-*---*---*---*---*---*---*---*---*----\n\t");
        
        c=getchar();
        switch(c)
        {
        case 'A':
          printf("\n\n\t�������Ǹ��˵�����:\n\t");
            scanf("%s",name);
            Tree=SearchTree(Tree,name,20);
            if(Tree==NULL)
            {
                printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n",name);
                break;
            }
            if(Tree->Parent==NULL&&Tree->NextNode[0]==NULL||Tree->Parent!=NULL&&Tree->Name!=Tree->Parent->NextNode[0]->Name)
            {
                printf("\n\n\t%s����û����ż���������ż",Tree->Name);
                break;
            }
            if(Tree->Parent==NULL&&(Tree->Num>20||Tree->Num<0))
                Tree->Num=0;
            if(k==1)
              Tree=Tree->Parent;
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\n\t�����������Ա����:\n\t");
            scanf("%s",NewNode->Name);
            printf("\n\n\t�����������Ա�Ա�ŮG��B:\n\t");
            scanf("%1s",&NewNode->Gender);
            num=Tree->Num;
            NewNode->NextNode[0]=(TreeNode *)malloc(sizeof(TreeNode));
            NewNode->NextNode[0]=NULL;
            NewNode->Num=0;
            NewNode->Parent=Tree;
            Tree->NextNode[num+1]=NewNode;
            Tree->Num=Tree->Num+1;
             printf("\n\n\t-------------��Ů����Ϣ��ӳɹ�----------------");
            break;
        case 'B':
          printf("\n\n\t�������Ǹ��˵�����:\n\t");
            scanf("%s",name);
            Tree=SearchTree(Tree,name,20);
            if(Tree->Parent!=NULL&&strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0||Tree->NextNode[0]!=NULL)
            {
                printf("\n\n\t�Ѿ�������ż");
                break;
            }
            if(Tree==NULL)
            {
                printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n",name);
                break;
            }
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\n\t�����������Ա����:\n\t");
            scanf("%s",NewNode->Name);
            printf("\n\n\t�����������Ա�Ա�ŮG��B:\n\t");
            scanf("%1s",&NewNode->Gender);
            NewNode->Parent=Tree;
            Tree->NextNode[0]=NewNode;
            break;
        case 'C':    
          printf("\n\n\t----------------������񵽴˽���-----------------");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!---------    ");
            printf("\n\t-----------�����ٴ�ѡ������ķ�����!-------------    ");
            printf("\n\t------------------лл����!----------------------\n\t");
            break;
        }
        if (c=='C'||c=='c')
            break;
          printf("\n\n\t--------------�밴Enter����������--------------");
        getchar();
        getchar();
    }
}
//�޸�ĳ���˵���Ϣ
void Change(TreeNode * Tree)
{
    char name[20];
    TreeNode * NewNode;
    printf("\n\t��������Ҫ�޸ĵ��˵���Ϣ:\n\t");
    scanf("%s",name);
  
    NewNode=SearchTree(Tree,name,20);
    if(NewNode==NULL)
    {
        printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n",name);
        return;
    }
    else 
    {
        SubMenue1(NewNode);
    }
}

//������˵�
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
        printf("\n\n\t           ---*****---��ѡ����Ĳ���---****---                 ");
        printf("\n\t---*---*---*---1:�޸ĸ��˵���Ϣ---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---2:�޸ĸ�ĸ����Ϣ---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---3:�޸��ֵܽ��õ���Ϣ---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---4:�޸���Ů����Ϣ---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---5:�޸���ż����Ϣ---*---*---*---*---*---*----    ");
        printf("\n\t---*---*---*---6:�˳�-*---*---*---*---*---*---*---*---*----\n\t");
        
        c=getchar();
        switch(c)
        {
        case 'A':
            printf("\n\n\t�������޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t");
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
               strcpy(Tree->Name,name);
            printf("\n\n\t�Ƿ�Ҫ�޸��Ա�:�����Ҫ������'1'����Ҫ�޸ľ�����'0'Ȼ��Enter������\n\t");
            scanf("%d",&flag);
            if (flag==1)
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                    Tree->Gender='B';
                else Tree->Gender='G';
            }
            printf("\n\n\t������Ϣ�޸ĳɹ�");
            break;
        case 'B':
            if(Tree->Parent==NULL)                                         //�ж��ǲ���ͷ�ڵ�
            {
                printf("\n\t���������ͼ����˵���û�и�ĸ��Ϣ!",name);
                break;
            }
            if (k==1)                                             //�ж��ǲ�����׸�����˼��
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                {  
                    printf("\n\n\t���Ǽ���˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
                }
                else
                {
                    printf("\n\n\t������׸�˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
                }
                break;
            }
            if(Tree->Parent->Gender=='G'||Tree->Parent->Gender=='g')
            {
                strcpy(Parent[0],"ĸ��");
                strcpy(Parent[1],"����");
            }
            else 
            {
                strcpy(Parent[0],"����");
                strcpy(Parent[1],"ĸ��");
            }
            
            printf("\n\n\t������%sҪ�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Parent[0]);
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
                strcpy(Tree->Parent->Name,name);
            printf("\n\n\t������%sҪ�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Parent[1]);
            scanf("%s",name);
            if(strcmp(name,"0")!=0)
                strcpy(Tree->Parent->NextNode[0]->Name,name);
            printf("\n\n\t-------------��ĸ����Ϣ�޸ĳɹ�----------------");
            break;
        case 'C':
            NewNode=Tree->Parent;
            if(NewNode==NULL)                                         //�ж��ǲ���ͷ�ڵ�
            {
                printf("\n\t���������ͼ����˵���û���ֵܽ�����Ϣ!",name);
                break;
            }
            if (k==1)                                             //�ж��ǲ�����׸�����˼��
            {
                if(Tree->Gender=='G'||Tree->Gender=='g')
                {  
                    printf("\n\n\t���Ǽ���˼�������ֵܽ�����Ϣ���ڼ����ڰ���");
                }
                else
                {
                    printf("\n\n\t������׸�˼�������ֵܽ�����Ϣ���ڼ����ڰ���");
                }
                break;
            }
            if(NewNode->Num==1)
            {
                printf("\n\n\tû���ֵܽ���");
                break;
            }
            else
            {
                for(i=1;i<=NewNode->Num;i++)
                {
                    if(NewNode->NextNode[i]->Name!=Tree->Name)
                    {
                        printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",NewNode->NextNode[i]->Name);
                        scanf("%s",name);
                        if(strcmp(name,"0")!=0)
                            strcpy(NewNode->NextNode[i]->Name,name);
                        
                        printf("\n\n\t�Ƿ�Ҫ�޸��Ա�:�����Ҫ������'1'����Ҫ�޸ľ�����'0'Ȼ��Enter������\n\t");
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
          printf("\n\n\t------------�ֵܽ��õ���Ϣ�޸ĳɹ�-------------");
            break;
        case 'D':
            if(Tree->Num==0)
            {
                printf("\n\n\t����û����Ů");
                break;
            }
            if (Tree->Parent !=NULL)
                if (strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0)       //���������׸�����Ǽ���ľ�������ż�ڵ�����޸�
                {
                    Tree=Tree->Parent;
                }
            for(i=1;i<=Tree->Num;i++)
            {        
                printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Tree->NextNode[i]->Name);
                scanf("%s",name);
                if(strcmp(name,"0")!=0)
                    strcpy(Tree->NextNode[i]->Name,name);
                
                printf("\n\n\t�Ƿ�Ҫ�޸��Ա�:�����Ҫ������'1'����Ҫ�޸ľ�����'0'Ȼ��Enter������\n\t");
                scanf("%d",&flag);
                if (flag==1)
                {
                    if(Tree->NextNode[i]->Gender=='G'||Tree->NextNode[i]->Gender=='g')
                        Tree->NextNode[i]->Gender='B';
                    else Tree->NextNode[i]->Gender='G';
                }
                
            }
          printf("\n\n\t---------------��Ů����Ϣ�޸ĳɹ�----------------");
            break;
        case 'E':
            if(Tree->Parent!=NULL)
            {
                if (Tree->NextNode[0]==NULL&&strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)!=0)
                {
                    printf("\n\n\t����û����ż");
                    break;
                }
                
                if (strcmp(Tree->Name,Tree->Parent->NextNode[0]->Name)==0)
                {
                    printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Tree->Parent->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->Parent->Name,name);        
                }
                else
                {
                    printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Tree->NextNode[0]->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->NextNode[0]->Name,name);
                }
            }
            else
            {
                if(Tree->NextNode[0]==NULL)
                    printf("\n\n\t����û����ż");
                else
                {
                    printf("\n\n\t������%s�޸ĵ�����:�������Ҫ�޸ľ����롮0��Ȼ��Enter������\n\t",Tree->NextNode[0]->Name);
                    scanf("%s",name);
                    if(strcmp(name,"0")!=0)
                        strcpy(Tree->NextNode[0]->Name,name);
                }
            }
          printf("\n\n\t---------------��ż����Ϣ�޸ĳɹ�----------------");
            break;
        case 'F':
          printf("\n\n\t----------------������񵽴˽���-----------------");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!---------");
            printf("\n\t-----------�����ٴ�ѡ������ķ�����!-------------");
            printf("\n\t------------------лл����!----------------------\n\t");
            break;
        }
        if (c=='F'||c=='f')
            break;
          printf("\n\n\t--------------�밴Enter����������--------------");
        getchar();
        getchar();
    }
}
//������˵�
void MainMenue(TreeNode *Tree)
{
    char c;
    char name[20];
    while(1)
    {
        system("cls");
        printf("\t");
        printf("\n\n\t         ---*****---��ѡ����Ĳ���---****---");
        printf("\n\t--------------1:���������Ϣ���������----------------------");
        printf("\n\t--------------2:�ڼ����в���ĳ�˲������Ӧ��Ϣ--------------");
        printf("\n\t--------------3:����µĳ�Ա--------------------------------");
        printf("\n\t--------------4:�������������Ϣ----------------------------");
        printf("\n\t--------------5:�޸�ĳ���˵���Ϣ----------------------------");
        printf("\n\t--------------6:�˳���������--------------------------------\n\t");
        
        c=getchar();
        switch(c)
        {
        case '1':
            TreeNode * NewNode;
            NewNode=(TreeNode *)malloc(sizeof(TreeNode));
            printf("\n\t����������:\n\t");
            scanf("%s",Tree->Name);
            printf("\n\t�������Ա�ŮG��B:\n\t");
            getchar();
            scanf("%c",&(Tree->Gender));
            Tree->Parent=NewNode;
            Tree->Parent=NULL;
            CreatTree(Tree);
            printf("\n\t--------------����ͼ�Ѿ������ɹ�---------------\n\n");
            printf("\n\n\t--------------�밴Enter����������--------------");
            getchar();
            break;
        case '2':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
                getchar();
                break;
            }
            printf("\n\t��������Ҫ���ҵ��˵�����:\n\t");
            scanf("%s",name);
            OutPutMessage(SearchTree(Tree,name,20),name,20);
            printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----\n\t");
            getchar();
            break;
        case '3':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
                getchar();
                break;
            }
            AddNew(Tree);
            getchar();
            break;
        case '4':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
                getchar();
                break;
            }
            printf("\n\n\t�������׵���Ҫ��Ϣ����:");
            OutPutAll(Tree);
            getchar();
            break;
        case '5':
            if(strcmp(Tree->Name,"0")==0)
            {
                printf("\n\t����ͼ�Ķ������δ�������Ƚ�����\n");
                getchar();
                break;
            }
            Change(Tree);
            getchar();
            break;
        case '6':
          printf("\n\n\t-----------------���η��񵽴˽���------------------");
            printf("\n\t------------------��ӭ�´�ʹ��---------------------");
            printf("\n\t----------------------лл-------------------------\n\n");
            break;
        case '\n':
            break;
        default:
          printf("\n\n\t--------�Բ���!���ѡ���ڷ���Χ֮��!-----------");
            printf("\n\t-----------�����ٴ�ѡ������ķ�����!---------------");
            printf("\n\t------------------лл����!------------------------\n\t");
            getchar();
            break;
        }
        if (c==6)
            break;
        
        getchar();
    }
}
//������
void CreatTree(TreeNode *Node)
{
    int i;
    TreeNode *NewNode;
    NewNode=(TreeNode *)malloc(sizeof(TreeNode));
    Node->NextNode[0]=NewNode;
    Node->NextNode[0]=NULL;
    //Node->Parent =NULL;
    printf("\n\t������%s����Ů����Ŀ:\n\t",Node->Name);
    scanf("%d",&(Node->Num));
    printf("\n\t������%s����ż������:\n\t",Node->Name);
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
        printf("\n\t������%s�ĵ�%d��Ů������\n\t",Node->Name,i);
        scanf("%s",NewNode->Name);
        printf("\n\t������%s�ĵ�%d��Ů���Ա�ŮG��B:\n\t",Node->Name,i);
        getchar();
        scanf("%c",&NewNode->Gender);
        NewNode->Num=0;
        NewNode->Parent=Node;
        Node->NextNode[i]=NewNode;
        CreatTree(Node->NextNode[i]);
    }
}
//������������е�����
void OutPutAll(TreeNode *Tree)
{
    int i, flag=0;
    printf("\n\t---****---***---***---***---***---***---***---***---***---");
    printf("\n\t����:%s �Ա�:",Tree->Name);
    if (Tree->Gender=='G'||Tree->Gender=='g')
    {
        flag=1;
        printf("Ů");
    }
    else 
        printf("��");
    if (!(Tree->NextNode[0]))
    { 
        printf("\n\t����û����ż����Ů\n");
        return;
    }
    if(flag==1)
        printf("\n\t�ɷ� ����:%s",Tree->NextNode[0]->Name);
    else
        printf("\n\t���� ����:%s",Tree->NextNode[0]->Name);
    for(i=1;i<=Tree->Num;i++)
    {
        printf("\n\t��%d����Ů������:%s �Ա�:",i,Tree->NextNode[i]->Name,Tree->NextNode[i]->Gender);
        if (Tree->NextNode[i]->Gender=='G'||Tree->NextNode[i]->Gender=='g')
            printf("Ů");
        else 
            printf("��");
    }
    printf("\n\t");
    for(i=1;i<=Tree->Num;i++)
    {
        OutPutAll(Tree->NextNode[i]);
    }
}
//�����о�����������ĳ����
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
//����Ѿ����ҵ����˵���Ϣ
void OutPutMessage(TreeNode * Tree,char name[],int length)
{
        int flag=0,i;
        TreeNode *NewNode;
            printf("\n\n\t-----*----*----*----*----*----*----*----*----*----*----");
        if(Tree==NULL)
        {
            printf("\n\n\t****�ü���ͼ��û��%s����˵���Ϣ��ȷ���Ƿ��������*****\n",name);
            return;
        }
        printf("\n\n\t����Ҫ�ҵ����Ѿ��ҵ���Ϣ������ʾ:");
        printf("\n\n\t����:%s\t�Ա�:",name);
    
        if (Tree->Gender=='G'||Tree->Gender=='g')
        { 
            flag=1;                                         //��ǳ�Ա�Ա�
            printf("Ů");
        }
        else 
            printf("��");
        NewNode=Tree->Parent;
        if (k==1)
        {
            
            if(flag==1)
            {  
                printf("\n\n\t���Ǽ���˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
                printf("\n\t�ɷ� ����:%s",NewNode->Name);
            }
            else
            {
                printf("\n\n\t������׸�˼�����Ը�ĸ��Ϣ���ڼ����ڰ���");
                printf("\n\t���� ����:%s",NewNode->Name);
            }
            if ((NewNode->Num)>0)                                //�жϳ�Ա���к���
            {        
                printf("\n\t�ĺ��ӵ���Ϣ����:");               //�����Ա�ĺ��ӵ���Ϣ
                for(i=1;i<=NewNode->Num;i++)
                {
                    printf("\n\t����:%s  �Ա�:",NewNode->NextNode[i]->Name);
                    
                    if (NewNode->NextNode[i]->Gender=='G'||NewNode->Gender=='g') 
                        printf("Ů");
                    else 
                        printf("��");
                }
            }
            return;
        }
                              
        if(NewNode==NULL)                                    //�ж����ǲ��Ǹ��ڵ�����ǵĻ���û�и�ĸ�ֵ���Ϣ
            printf("\n\t���������ͼ����˵���û�и�ĸ���ֵܽ�����Ϣ!",name);
        else
        {
            if (NewNode->Gender=='G'||NewNode->Gender=='g')      //�жϸ��׽ڵ��Ǹ��׻���ĸ��
            {                                                 //������������ĸ�ĸ�׵���Ϣ
                printf("\n\tĸ�� ����:%s",NewNode->Name);
                printf("\n\t���� ����:%s",NewNode->NextNode[0]->Name);
            }
            else 
            {
                printf("\n\tĸ�� ����:%s",NewNode->NextNode[0]->Name);
                printf("\n\t���� ����:%s",NewNode->Name);
            }
            if (NewNode->Num>1)                             //�ж���(��)�Ƿ����ֵܽ���
            {                                                //�����(��)���ֵܽ��õ���Ϣ
                printf("\n\t%s���ֵܽ�����Ϣ����:",name);                                            
                for(i=1;i<=NewNode->Num;i++)
                {
                    if(NewNode->NextNode[i])
                        printf("\n\t%s����:%s  �Ա�:",NewNode->NextNode[i]->Name,NewNode->NextNode[i]->Name);
                    
                    if (NewNode->NextNode[i]->Gender=='G'||Tree->Gender=='g')
                        printf("Ů");
                    else 
                        printf("��");
                }
            }
            else
                printf("\n\t%sû���ֵܽ���!",Tree->Name);
        }
        if(Tree->NextNode[0]!=NULL)                         //�ж���(��)�Ƿ�����ż
        {                                                //�����(��)����ż����Ϣ
            if(flag==1)
                printf("\n\t�ɷ� ����:%s",Tree->NextNode[0]->Name);
            else
                printf("\n\t���� ����:%s",Tree->NextNode[0]->Name);
            if (Tree->Num>0)                             //�ж���(��)�Ƿ��к���
            {        
                printf("\n\t�ĺ��ӵ���Ϣ����:");       //�����(��)�ĺ��ӵ���Ϣ
                for(i=1;i<=Tree->Num;i++)
                {
                    printf("\n\t����:%s  �Ա�:",Tree->NextNode[i]->Name);
                    
                    if (Tree->NextNode[i]->Gender=='G'||Tree->Gender=='g') 
                        printf("Ů");
                    else 
                        printf("��");
                }
            }
            else
                printf("\n\t%s����û�к���",name);
        }
        else 
            printf("\n\t%s����û����ż�ͺ���\n",Tree->Name);    
}

