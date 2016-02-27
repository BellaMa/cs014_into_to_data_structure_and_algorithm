#include <iostream>
#include <string.h>
#include "MyList.h"
#include <assert.h> 
using namespace std;

MyList::MyList()
{
    head = 0;
    length = 0;
}

MyList::MyList(const MyList& str)
{
    this->length = 0;
    this->head = 0;
    
    if(str.head != 0)
    {
        Node *cur_str = str.head;
        this->head = new Node(cur_str->value);
        Node *cur_tem = this->head;
        this->head->next = this->head;
        this->head->pred = this->head;
        cur_str = cur_str->next;
        //if there is more than one node
        while(cur_str != str.head)
        {
            cur_tem->next = new Node(cur_str->value);
            cur_tem->next->next = this->head;
            this->head->pred = cur_tem->next;
            cur_tem->next->pred = cur_tem;
            
            cur_tem = cur_tem->next;
            cur_str = cur_str->next;
        }
        this->length = str.length;
    }
}

MyList::MyList(const string& str)
{
    length = 0;
    head = 0;
    if(str != "")
    {
        char tem = str.at(0);
        head = new Node(tem);
        Node *cur_node = head;
        cur_node->next = cur_node;
        cur_node->pred = cur_node;

        for(unsigned i = 1; i < str.length(); ++i)
        {
            tem = str.at(i);
            cur_node->next = new Node(tem);
            cur_node->next->next = head;
            head->pred = cur_node->next;
            cur_node->next->pred = cur_node;
            
            cur_node = cur_node->next;
        }
        
        length = str.length();
    }
}


MyList::MyList(const char* str)
{
    length = 0;
    head = 0;
    
    if(strlen(str) != 0)
    {
        char tem = str[0];
        head = new Node(tem);
        Node *cur_node = head;
        cur_node->next = cur_node;
        cur_node->pred = cur_node;

        for(unsigned i = 1; i < strlen(str); ++i)
        {
            tem = str[i];
            cur_node->next = new Node(tem);
            cur_node->next->next = head;
            head->pred = cur_node->next;
            cur_node->next->pred = cur_node;
            
            cur_node = cur_node->next;
        }
        
        length = strlen(str);
    }
    
}


MyList::~MyList()
{
    length = 0;
    while(head != 0)
        pop_front();
    
}


void MyList::push_front(char value)
{
    ++length;
    
    Node* newNode = new Node(value);
    if(head != 0)
    {
        newNode->next = head;
        newNode->pred = head->pred;
        head->pred->next = newNode;
        head->pred = newNode;
        head = newNode;
    }
    else 
        {
            head = newNode;
            head->next = head;
            head->pred = head;
        }
}

//the dif from push_front() is what head is pointing at
void MyList::push_back(char value)
{
    ++length;
    
    Node* newNode = new Node(value);
    if(head != 0)
    {
        newNode->next = head;
        newNode->pred = head->pred;
        head->pred->next = newNode;
        head->pred = newNode;
    }
    else 
        {
            head = newNode;
            head->next = head;
            head->pred = head;
        }
}



void MyList::pop_front()
{
    if(head != 0)
    {
        //if onle one node, need to make head null
        if(head->next == head)
        {
            delete head;
            head = 0;
            --length;
            return;
        }
        
        Node* tem = head->next;
        tem->pred = head->pred;
        head->pred->next = tem;
        delete head;
        head = tem;
        
        --length;
    }
}

//the dif from pop_front() is what head is pointing at 
void MyList::pop_back()
{
    if(head != 0)
    {
        //if onle one node, need to make head null
        if(head->next == head)
        {
            delete head;
            head = 0;
            --length;
            return;
        }
        
        Node* tem = head->pred;
        tem->pred->next = head;
        head->pred = tem->pred;
        delete tem;
        
        --length;
    }
}


void MyList::swap(int i, int j)
{
    if(length == 0)
    {
        cout << "out-of-range: " << endl
             << "it's an empty list" << endl;
        return ;
    }
    if(i > (length - 1) || j > (length - 1))
    {
        if(i > (length - 1) && j > (length - 1))
        {
            cout << "out-of-range: " << endl
             << "both i and j are larger than the list's range" 
             << endl;
             return ;
        }
        else if(i > (length - 1))
        {
            cout << "out-of-range: " << endl
                 << "i is larger than the list's range"
                 << endl;
            return ;
        }
        else 
        {
            cout << "out-of-range: " << endl
                 << "j is larger than the list's range"
                 << endl;
            return ;
        }
    }
    
    Node* tem_i = head;
    Node* tem_j = head;
    int cur_i = 0;
    int cur_j = 0;
    
    while(cur_i != i)
    {
        ++cur_i;
        tem_i = tem_i->next;
    }
    while(cur_j != j)
    {
        ++cur_j;
        tem_j = tem_j->next;
    }
    
    char tem = tem_i->value;
    tem_i->value = tem_j->value;
    tem_j->value = tem;
    
}

void MyList::insert_at_pos(int i, char value)
{
    if(length == 0)
    {
        if(i == 0)
        {
            push_back(value);
            
            return ;
        }
        else
        {
            cout << "out-of-range: " << endl
             << "it's an empty list" << endl;
             
            return ;
        }
    }
    //can insert after last item
    if(i <= length )
    {
        if(i == 0)
        {
            push_front(value);
            return ;
        }
        else
        {
            int tem_i = 0;
            Node* newNode = new Node(value);
            Node* cur_node = head;
            while(tem_i != i)
            {
                ++tem_i;
                cur_node = cur_node->next;
            }
            newNode->next = cur_node;
            newNode->pred = cur_node->pred;
            cur_node->pred->next = newNode;
            cur_node->pred = newNode;
            
            ++length;
        }
        
    }
    else
    {
        cout << "out-of-range: " << endl
             << "i is larger than the list's range"
             << endl;
        return ;
    }
    
    
}

void MyList::reverse()
{
    if(head == 0)
        return;
        
    Node* cur_node = head;
    Node* tem = cur_node->next;
    while(cur_node->next != head)
    {
        cur_node->next = cur_node->pred;
        cur_node->pred = tem;
        
        cur_node = tem;
        tem = tem->next;
    }
    cur_node->next = cur_node->pred;
    cur_node->pred = tem;
    head = cur_node;
    
}



int MyList::size() const
{
    return (int)length;
}

void MyList::print() const
{
    Node* cur_node = head;
    if(head != 0)
    {
        cout << cur_node->value;
        cur_node = cur_node->next;
        while(cur_node != head)
        {
            cout << cur_node->value;
            cur_node = cur_node->next;
        }
    }
    cout << endl;
    //else
        //cout << "empty list" << endl; //remember to comment out this line!
    
}


int MyList::find(char value) const
{
    if(head == 0)
    {
        return -1;
    }
    
    Node* cur_node = head;
    int i = 0;
    while(i < length)
    {
        if(cur_node->value == value)
            return i;
        
        ++i;
        cur_node = cur_node->next;
    }
    
    return -1;
}

int MyList::find(MyList& query_str) const
{
    int i = 0;
    Node* cur_node = this->head;
    Node* tem_node = 0;
    Node* cur_query = query_str.head;
    Node* tem_query = 0;
    
    if(length == 0)
    {
        return -1;
    }
    
    while(i < length)
    {
        tem_node = cur_node;
        tem_query = cur_query;// = query_sty.head
        
        if(cur_node->value == cur_query->value)
        {
            //query_str only has one node
            if(cur_query->next == cur_query)
            {
                return i;
            }
            else
            {
                tem_node = tem_node->next;
                tem_query = tem_query->next;
                while(tem_node->value == tem_query->value)
                {
                    tem_node = tem_node->next;
                    tem_query = tem_query->next;
                    if(tem_query == cur_query)
                        return i;
                }
                
                ++i;
                cur_node = cur_node->next;
                
            }
            
        }
        else
        {
            cur_node = cur_node->next;
            ++i;
        }
    }
    
    return -1;
}



MyList& MyList::operator= (const MyList& str)
{
    if(this != &str)
    {
        //clear list
        if(length != 0)
        {
            while(head != 0)
            {
                pop_back();
            }
        }
        
        
        if(str.length == 0)
            return *this;
            
        Node* cur_str = str.head;
        push_back(cur_str->value);
        cur_str = cur_str->next;
        while(cur_str != str.head)
        {
            push_back(cur_str->value);
            cur_str = cur_str->next;
        }
        
        length = str.length;
    }

    return *this;
}


char& MyList::operator[](const int i)
{
    if(i >= length)
    {
        cout << "out-of-range: i is too big" << endl;
        cout << "As a sircularly linked list, I will convert i into the correcet value" << endl;
        cout << "Be careful next time =.=" << endl;
    }
    
    int tem_i = 0;
    Node* cur_node = head;
    while(tem_i != i)
    {
        ++tem_i;
        cur_node = cur_node->next;
    }
    return cur_node->value;
    
    
    
    
    
}

MyList& MyList::operator+(const MyList& str)
{
    if(str.head == 0)
        return *this;
    
    Node* tem_node = str.head;
    push_back(tem_node->value);
    tem_node = tem_node->next;
    while(tem_node != str.head)
    {
        push_back(tem_node->value);
        tem_node = tem_node->next;
    }
    return *this;
}


int main()
{
    cout << "test constructors" <<endl;
    MyList list_01;
    MyList list_02("GOD BLESS ME!");
    char str[] = "GOOD LUCK";
    MyList list_03(str);
    MyList list_04(list_02);
    MyList list_empty;


    list_01.print();
    list_02.print();
    list_03.print();
    list_04.print();
   
    cout << "----------------------" << endl;
    cout << "test push_back() " << endl;
    list_01.push_back('a');
    list_01.print();
    cout << list_01.size() << endl;
    list_03.push_back('a');
    cout << list_03.size() << endl;
    list_03.print();
    
    cout << "----------------------" << endl;
    cout << "test pop_back() " << endl;
    list_01.pop_back();
    list_01.print();
    cout << list_01.size() << endl;
    list_03.pop_back();
    cout << list_03.size() << endl;
    list_03.print();
    
    cout << "----------------------" << endl;
    cout << "test push_front() " << endl;
    list_01.push_front('a');
    cout << list_01.size() << endl;
    list_01.print();
    list_03.push_front('a');
    cout << list_03.size() << endl;
    list_03.print();
    
    cout << "----------------------" << endl;
    cout << "test pop_front() " << endl;
    list_01.pop_front();
    cout << list_01.size() << endl;
    list_01.print();
    list_03.pop_front();
    cout << list_03.size() << endl;
    list_03.print();
    
    cout << "----------------------" << endl;
    cout << "test swap() " << endl;
    MyList list_05("12345");
    list_05.swap(0,0);
    list_05.print();
    list_05.swap(0,1);
    list_05.print();
    list_05.swap(4,3);
    list_05.print();
    list_05.swap(7,0);
    list_05.print();
    list_05.swap(0,7);
    list_05.print();
    list_05.swap(7,7);
    list_05.print();
   
    cout << "----------------------" << endl;
    cout << "test insert_at_pos() " << endl;
    MyList list_06("12345");
    list_06.insert_at_pos(0,'7');
    list_06.print();
    cout << list_06.size() << endl;
    list_06.insert_at_pos(6,'7');
    list_06.print();
    list_06.insert_at_pos(9,'7');
    list_06.print();
    list_empty.insert_at_pos(1,'a');
    //list_empty.print();
    list_empty.insert_at_pos(0,'a');
    cout << list_empty.size() << endl;
    list_empty.print();
    list_empty.pop_back();
 
    cout << "----------------------" << endl;
    cout << "test reverse() " << endl;
    MyList list_07("12345");
    list_07.reverse();
    list_07.print();
    list_empty.reverse();
    list_empty.print();

    cout << "----------------------" << endl;
    cout << "test size() " << endl;
    MyList list_08("12345");
    cout << list_08.size() << endl;
    cout << list_empty.size() << endl;

    cout << "----------------------" << endl;
    cout << "test find(char ) " << endl;
    MyList list_09("12345");
    cout << list_09.find('5') << endl;
    cout << list_09.find('9') << endl;
    cout << list_empty.find('1') << endl;


    cout << "----------------------" << endl;
    cout << "test find(MyList) " << endl;
    MyList list_tem("345");
    cout << list_09.find(list_tem) << endl;
    MyList list_tem_01("28");
    cout << list_09.find(list_tem_01) << endl;


    cout << "----------------------" << endl;
    cout << "test = " << endl;
    list_01.print();
    list_02.print();
    list_01 = list_02;
    list_03.print();
    list_01.print();
    list_03 = list_03;
    list_03.print();
    cout << list_03.size() << endl;
    list_03 = list_02;
    list_03.print();
    cout << list_03.size() << endl;
    cout << list_02.size() << endl;
    list_03 = list_empty;
    list_03.print();
    cout << list_03.size() << endl;

    cout << "----------------------" << endl;
    cout << "test [] " << endl;
    MyList list_10("1234");
    cout << list_10[3] << endl; 
    cout << list_10[4] << endl;


    cout << "----------------------" << endl;
    cout << "test + " << endl;
    list_02.print();
    list_04.print();
    list_02 = list_02 + list_04;
    list_02.print();
    

    return 0;
}
