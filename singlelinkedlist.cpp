#include <iostream>
using namespace std;

class Node
{ 
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key1, int data1)
    {
        key = key1;
        data = data1;
        next = NULL;
    }
};

class Single_Linked_list
{
public:
    Node *head;

    Single_Linked_list()
    {
        head = NULL;
    }

    Single_Linked_list(Node *node)
    {
        head = node;
    }

    Node *Node_exists(int k)
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    void append_node(Node *n)
    {
        if (Node_exists(n->key) != NULL)
        {
            cout << "Node Already exists with key " << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
            n->next = NULL;
            cout << "Node Appended." << endl;
        }
    }

    void prepend_node(Node *n)
    {
        if (Node_exists(n->key) != NULL)
        {
            cout << "Node Already exists with key " << n->key << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended." << endl;
        }
    }

    void insert_node_after_Particular_node(int key, Node *n)
    {
        Node *ptr = Node_exists(key);

        if (ptr == NULL)
        {
            cout << "No node exists with the key value " << key << endl;
        }
        else
        {
            if (Node_exists(n->key) != NULL)
            {
                cout << "Node Already exists with key " << n->key << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted after key " << key << "." << endl;
            }
        }
    }

    void delete_Particular_key_node(int key)
    {
        if (head == NULL)
        {
            cout << "The list is empty, nothing to delete." << endl;
            return;
        }

        Node *temp = Node_exists(key);
        if (temp == NULL)
        {
            cout << "No node exists with the key value " << key << endl;
            return;
        }

        if (head->key == key)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Node with key " << key << " deleted." << endl;
        }
        else
        {
            Node *prev = head;
            Node *current = head->next;

            while (current != NULL && current->key != key)
            {
                prev = current;
                current = current->next;
            }

            if (current != NULL)
            {
                prev->next = current->next;
                delete current;
                cout << "Node with key " << key << " deleted." << endl;
            }
        }
    }

    void update_Node_given_key(int key, int d)
    {
        Node *ptr = Node_exists(key);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully." << endl;
        }
        else
        {
            cout << "Node doesn't exist with the given key value " << key << "." << endl;
        }
    }

    void printlist()
    {
        if (head == NULL)
        {
            cout << "No Nodes to display." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Single_Linked_list s1;
    int option;
    int key1, data1, k1;

    do
    {
        cout << "\nSelect an operation to perform: " << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node After" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Update Node" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "0. Exit" << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 1:
            cout << "Enter key and data to append: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s1.append_node(n1);
            break;

        case 2:
            cout << "Enter key and data to prepend: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s1.prepend_node(n1);
            break;

        case 3:
            cout << "Enter the key after which you want to insert the node: ";
            cin >> k1;
            cout << "Enter key and data of the new node: ";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s1.insert_node_after_Particular_node(k1, n1);
            break;

        case 4:
            cout << "Enter the key of the node to delete: ";
            cin >> k1;
            s1.delete_Particular_key_node(k1);
            break;

        case 5:
            cout << "Enter the key and new data to update: ";
            cin >> key1 >> data1;
            s1.update_Node_given_key(key1, data1);
            break;

        case 6:
            cout << "Printing the list:" << endl;
            s1.printlist();
            break;

        case 7:
            cout << "\033[2J\033[1;1H"; // Clear screen for Unix-based systems
            break;

        case 0:
            break;

        default:
            cout << "Enter a valid option." << endl;
        }

    } while (option != 0);

    return 0;
}
