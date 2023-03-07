#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  int empty_lists_count = 0;
  ListNode* head = NULL;
  // ListNode* temp_node;
  ListNode* tail;
  int lowest_val;
  int list_with_lowest_val = -1;
  int i = 0;

  if (lists.size() == 0)
    return NULL;

  if (lists.size() == 1)
    return lists[0];

  // Check if all lists are empty and
  // find the smallest node if all lists are not empty
  for (ListNode* list : lists) {
    if (list == NULL)
      empty_lists_count++;
    else {
      // list is not empty

      if (list_with_lowest_val == -1) {
        list_with_lowest_val = i;
        lowest_val = list->val;
      } else {
        if (list->val < lowest_val) {
          lowest_val = list->val;
          list_with_lowest_val = i;
        }
      }
    }
    i++;
  }

  // cout << "Empty lists count: " << empty_lists_count << "\n";
  // cout << "Total list count: " << lists.size() << endl;

  if (empty_lists_count == lists.size())
    return NULL;

  // Set head (first node in the final list)
  head = lists[list_with_lowest_val];
  lists[list_with_lowest_val] = lists[list_with_lowest_val]->next;
  head->next = NULL;
  // Intially tail is same as head
  tail = head;

  // keep looping until one list is remaining
  // we will join this list to the tail node after the loop
  while (empty_lists_count < lists.size() - 1) {
    empty_lists_count = 0;
    list_with_lowest_val = -1;
    i = 0;
    for (ListNode* list : lists) {
      if (list == NULL) {
        empty_lists_count++;
      } else {
        // list is not empty

        if (list_with_lowest_val == -1) {
          list_with_lowest_val = i;
          lowest_val = list->val;
        } else {
          if (list->val < lowest_val) {
            lowest_val = list->val;
            list_with_lowest_val = i;
          }
        }
      }
      i++;
    }

    tail->next = lists[list_with_lowest_val];
    tail = tail->next;
    lists[list_with_lowest_val] = lists[list_with_lowest_val]->next;
    tail->next = NULL;
  }

  // find list that is not empty
  i = 0;
  for (ListNode* list : lists) {
    // cout << "checking list " << i;
    if (list != NULL) {
      // cout << " not empty: ";
      // printLinkedList(lists[i]);
      tail->next = lists[i];
      break;
    }
    // cout << endl;
    i++;
  }

  return head;
}

int main(int argc, char const* argv[]) {
  vector<ListNode*> lists;

  // lists.push_back(createLinkedList({1, 4, 5}));
  // lists.push_back(createLinkedList({1, 3, 4}));
  // lists.push_back(createLinkedList({2, 6}));

  // lists.push_back(createLinkedList({1, 4, 7, 8, 9}));
  // lists.push_back(createLinkedList({0, 5, 20}));
  lists.push_back(createLinkedList({}));
  lists.push_back(createLinkedList({1}));
  // lists.push_back(createLinkedList({2, 3}));

  for (auto list : lists) {
    printLinkedList(list);
  }

  printLinkedList(mergeKLists(lists));

  return 0;
}
