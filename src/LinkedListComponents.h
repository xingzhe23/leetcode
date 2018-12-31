/*
We are given head, the head node of a linked list containing unique integer values.
We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:
Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.
*/

#include "ListNode.h"
#include <vector>
#include <iostream>
#include<unordered_set>

namespace LinkedListComponents{

    class solution {
        public:

        static int solution_func(ListNode* header, std::vector<int> components) {
            int res = 0;
            std::unordered_set<int> components_set(components.begin(), components.end());
            while(header) {
                if(components_set.count(header->value) != 0 && (!header->pNext || components_set.count(header->pNext->value) != 0)) {
                    res++;
                }
                header = header->pNext;
            }
            
            return res;
        }

        static void test() {

            // 1->2->3->4->5->6->7...->10
            //component [ 1, 3, 5, 6]

            //componet2 [ 1 3 4 8, 9 10]

            ListNode * pHeader = new ListNode;
            pHeader->value = 1;
            pHeader->pNext = nullptr;
            ListNode* pTmp = pHeader;
        
            for(int i = 2; i <= 10; i++) {
                ListNode * node = new ListNode;
                node->value = i;
                node->pNext = nullptr;
                pTmp->pNext = node;
                pTmp = node;
            }

            std::vector<int> component;
            component.push_back(1);
            component.push_back(3);
            component.push_back(5);
            component.push_back(6);

            std::cout<<std::endl;
            std::cout<< " component num : " << solution_func(pHeader, component) <<std::endl;

            component.clear();
            component.push_back(1);
            component.push_back(3);
            component.push_back(4);
            component.push_back(7);
            component.push_back(8);
            component.push_back(9);
            std::cout<<" component num:" << solution_func(pHeader, component) << std::endl;
        }
    };

}