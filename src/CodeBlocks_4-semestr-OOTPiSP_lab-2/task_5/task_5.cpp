#include "task_5.hpp"

struct Node
{
    static Node* head;
    Node* next;
    string word;
    int counter;

    Node();
    void add_node(string word);
    void show();
    void print();
    void print_table();
    void del();
    ~Node();
};

Node::Node()
{
    //cout << this << " construct" << endl;
    this->word = "-";
    this->counter = 0;
    this->next = NULL;
}

void Node::add_node(string word)
{
    for (struct Node* temp = head; temp != NULL; temp = temp->next)
    {
        if (word == temp->word)
        {
            (temp->counter)++;
            return;
        }
    }

    struct Node* new_node = new struct Node;
    new_node->word = word;
    new_node->counter = 1;
    new_node->next = head;
    head = new_node;
}

void Node::show()
{
    cout << "{" << endl
        << "\t" << "\"this\": " << "\"" << this << "\"" << endl
        << "\t" << "\"next\": " << "\"" << this->next << "\"," << endl
        << "\t" << "\"word\": " << "\"" << this->word << "\"," << endl
        << "\t" << "\"counter\": " << "\"" << this->counter << "\"," << endl
    << "}" << endl;

}

void Node::print()
{
    for (struct Node* temp = head; temp != NULL; temp = temp->next)
    {
        temp->show();
    }
}

void Node::print_table()
{
    //what length?
    int length = 0;
    for (struct Node* temp = head; temp != NULL; temp = temp->next)
    {
        length++;
    }
    //create array
    Node* arr = new Node [length];
    //copy list ro array
    int i = 0;
    for (struct Node* temp = head; temp != NULL; temp = temp->next)
    {
        arr[i].word = temp->word;
        arr[i].counter = temp->counter;
        arr[i].next = NULL;
        i++;
    }
    //sort array
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (arr[i].counter > arr[j].counter)
            {
                Node temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //print sorted table
    for (int i = 0; i < length; i++)
    {
        cout << arr[i].counter << "\t"<< arr[i].word << endl;
    }
    //delete array
    delete [] arr;
}

void Node::del()
{
    for (struct Node* temp = head; temp != NULL;)
    {
        struct Node* x = temp;
        temp = temp->next;
        delete x;
    }
}

Node::~Node()
{
    //cout << this << " destruct" << endl;
}

Node* Node::head = NULL;

void task_5()
{
    struct Node myList; //list for word with counter
    ifstream fin; //for read file
    fin.open("loremru1000.txt"); //open file
    if(!fin.is_open()) //if file not open then do
    {
        cout << "err open" << endl;
    }
    else //if file open then do
    {
        string word;
        char ch;
        while(fin.get(ch))
        {
            if (ch == ' ')
            {
                //cout << word << endl;
                myList.add_node(word);
                word = "";
            }
            else
            {
                word += ch;
            }
            //cout << ch;
        }
    }
    //myList.print();
    myList.print_table();
    fin.close();
    myList.del();
}
