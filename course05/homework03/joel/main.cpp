#include "linkedlist.cpp"
#include <iostream>
#include <vector>
int main()
{
    // with strings
	Node<std::string> ll1{"this is a test"};
    std::cout << ll1.GetData() << std::endl;

	auto &n1 = ll1.Append("This is another test");
	std::cout << n1.GetData() << std::endl;
    if (ll1.Next())
    {
        std::cout << ll1.Next()->GetData() << std::endl;
    }


    // or ints
    Node<int> ll2{1};
    auto &n2 = ll2.Append(3);
    std::cout << n2.GetData() << std::endl;

    boost::optional<Node<int>&> cur_node = ll2;
    int count = 0;
    while (cur_node){
        printf("Node number %d\n", count);
        printf("Node contents '%d'\n", cur_node->GetData());
        cur_node = cur_node->Next();
        count++;
    }
    Node<std::vector<int>> ll3{std::vector<int>{1, 2, 3}};
    ll3.Append(std::vector<int>{3, 4, 5});
    ll3.Append(std::vector<int>{6, 7, 8});

    boost::optional<Node<std::vector<int>>&> cur_node2 = ll3;
    count = 0;
    while (cur_node2){
        printf("Node number %d\n", count);
        printf("Node contents:\n");
        for (auto i: cur_node2->GetData())
            printf("\t%d\n", i);

        cur_node2 = cur_node2->Next();
        count++;
    }

    Node<int> ll4{0};
    ll4.Append(1);
    ll4.Append(2);
    ll4.Append(3, 0);

    boost::optional<Node<int>&> cur_node3 = ll4;
    count = 0;
    while (cur_node3){
        printf("Node number %d\n", count);
        printf("Node contents: '%d'\n", cur_node3->GetData());

        cur_node3 = cur_node3->Next();
        count++;
    }

}
