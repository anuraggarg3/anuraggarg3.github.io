Ordered set is a policy based data structure in g++ that keeps the unique elements in sorted order. It performs all the operations as performed by the set data structure in STL in log(n) complexity and performs two additional operations also in log(n) complexity .

order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).
Required header files to implement ordered set and their description

For implementing ordered_set and GNU C++ library contains other Policy based data structures we need to include :



// Common file
include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
include <ext/pb_ds/tree_policy.hpp>
The first one is used to include the associative containers or group of templates such as set, multimap, map etc.The tree-based data structures which we will be using below is present in this header file.
The second header file is used to include the tree_order_statistics_node update which is explained below:

using namespace __gnu_pbds;
It is a namespace necessary for the GNU based Policy based data structures.

The tree based container has a concrete structure but the necessary structure required for the ordered set implementation is :

tree < int ,  null_type ,  less ,  rb_tree_tag ,  tree_order_statistics_node_update >
int : It is the type of the data that we want to insert (KEY).It can be integer, float or pair of int etc.
null_type : It is the mapped policy. It is null here to use it as a set.If we want to get map but not the set, as the second argument type must be used mapped type.
less : It is the basis for comparison of two functions.
rb_tree_tag : type of tree used. It is generally Red black trees because it takes log(n) time for insertion and deletion while other take linear time such as splay_tree.
tree_order_statistics_node__update : It is included in tree_policy.hpp and contains various operations for updating the node variants of a tree-based container, so we can keep track of metadata like the number of nodes in a subtree
Additional functions in the ordered set other than the set

Along with the previous operations of the set, it supports two main important operations

find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
Difference between set and ordered set
There is not so much difference between the set and ordered set although ordered set can be assumed as an extended version of set capable of performing some more advanced functions(stated above) that are extensively used in competitive programming.

NOTE : ordered_set is used here as a macro given to tree<int, null_type, less, rb_tree_tag, tree_order_statistics_node_update>. Therefore it can be given any name as macro other than ordered_set but generally in the world of competitive programming it is commonly referred as ordered set as it is a set with additional operations.
Practical applications:
Suppose we have a situation where the elements are inserted one by one in an array and after each insertion, we are given a range [l, r] and we have to determine the number of elements in the array greater than equal to l and less than equal to r. Initially, the array is empty.
Examples:



Input :    5
           1 2
           1
           2 5
           2
           1 5

Output :   0
           1
           3
Explanation:

Initially, the array is empty
5 is inserted.
Count of elements greater than equal to 1 and less than equal to 2 is 0.
1 is inserted.
Count of elements greater than equal to 2 and less than equal to 5 is 1 i.e. 5.
2 is inserted.
Count of elements greater than equal to 1 and less than equal to 5 is 3 i.e. 5, 1, 2.
Input :     1
            1 2
            2
            3 5
            5
            1 4
Output :    1
            0
            2
Initially, the array is empty

1 is inserted.
Count of elements greater than equal to 1 and less than equal to 2 is 1 i.e 1.
2 is inserted.
Count of elements greater than equal to 3 and less than equal to 5 is 0.
5 is inserted.
Count of elements greater than equal to 1 and less than equal to 4 is 2 i.e. 1, 2.
If we use set in STL find upper_bound on set, it gives only the address of the element and we can only find the value at that address by using dereferencing operator (*).

Suppose if we have a set as {0, 1, 2, 7, 8, 20} and we find upper_bound of 2, then it returns an address corresponding to the position of the element (7 in this case) in the set and we CANNOT subtract the starting address of the set (s.begin()) to find the number of elements smaller than 2 as in case of vector.
So, Here comes the need of the ordered set.

NOTE : The above functions can be implemented with the help of some other logic and data structure but the use of ordered set makes the code compact and can be implemented easily and speedily.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Implementation of the ordered set


// C++ program to demonstrate the
// ordered set in GNU C++
#include <iostream>
using namespace std;
  
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  
// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set
    ordered_set o_set;
  
    // insert function to insert in
    // ordered set same as SET STL
    o_set.insert(5);
    o_set.insert(1);
    o_set.insert(2);
  
    // Finding the second smallest element
    // in the set using * because
    //  find_by_order returns an iterator
    cout << *(o_set.find_by_order(1)) 
         << endl;
  
    // Finding the number of elements
    // strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;
  
    // Finding the count of elements less 
    // than or equal to 4 i.e. strictly less
    // than 5 if integers are present
    cout << o_set.order_of_key(5) 
         << endl;
  
    // Deleting 2 from the set if it exists
    if (o_set.find(2) != o_set.end())
        o_set.erase(o_set.find(2));
  
    // Now after deleting 2 from the set
    // Finding the second smallest element in the set
    cout << *(o_set.find_by_order(1)) 
         << endl;
  
    // Finding the number of
    // elements strictly less than k=4
    cout << o_set.order_of_key(4) 
         << endl;
  
    return 0;
}
Output

2
2
2
5
1
Thus we can now solve the above problem easily i.e. count of elements between l and r can be found by:
o_set.order_of_key(r+1) – o_set.order_of_key(l)
