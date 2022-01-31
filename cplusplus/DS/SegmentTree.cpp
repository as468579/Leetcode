#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>


struct SegmentNode{
public:
    SegmentNode *m_left;
    SegmentNode *m_right;
    SegmentNode(
		int sum, 
        int start, 
        int end, 
        SegmentNode *left=nullptr, 
        SegmentNode *right=nullptr
	): 
        m_sum(sum), 
        m_start(start),
        m_end(end),
        m_left(left),
        m_right(right){}

    ~SegmentNode(){}
public:
    int m_sum;
    int m_start;
    int m_end;
};

class SegmentTree{
public:
    SegmentTree(
		std::vector<int> &nums,
		int start,
		int end):
			m_root(buildTree(nums, start, end)){}

    SegmentNode* buildTree(
        std::vector<int>&nums, 
        int start, 
        int end
	){
		// std::cout << "start: " << start << ", end: " << end << std::endl;
        if(start==end){
        	// std::cout << nums[start] << std::endl;
            return new SegmentNode(nums[start], start, end);
        }

        int mid = (start + end) / 2;
        SegmentNode *left  = buildTree(nums, start, mid);
        SegmentNode *right = buildTree(nums, mid+1, end);
        // std::cout << (left->m_sum)+(right->m_sum) << std::endl;
        return new SegmentNode(
            (left->m_sum)+(right->m_sum),
            start,
            end,
            left,
            right
        );
    }

    int getSum(int start, int end, SegmentNode *root){
		
		// std::cout << "start: " << start << ", end: " << end << std::endl;
        if((start == root->m_start) && (end == root->m_end)){
            return root->m_sum;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(end <= mid){ 
            return getSum(start, end, root->m_left);
        }

        if(start > mid){
            return getSum(start, end, root->m_right);
        }

        return 
            getSum(start, mid, root->m_left ) + 
            getSum(mid+1, end, root->m_right);
    }

    void update(int index, int value, SegmentNode* root){

        if(((root->m_start) == index) && ((root->m_end) == index)){
            root->m_sum = value;
            return;
        }

        int mid = ((root->m_start) + (root->m_end)) / 2;
        SegmentNode *updatedNode = (index <= mid) ? (root->m_left) : (root->m_right); 
        update(index, value, updatedNode);
        root->m_sum = (root->m_left->m_sum) + (root->m_right->m_sum);
    	return;
    }

    void deleteTree(SegmentNode *root){
        if(!root) return;
        deleteTree(root->m_left);
        deleteTree(root->m_right);
        delete root;
    }
    ~SegmentTree(){}
public:
    SegmentNode *m_root;
};


int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr+6);
    
    std::cout << "Verify buildTree() and getSum()" << std::endl; 
    SegmentTree sgtTree(vec, 0, 5);
    assert(sgtTree.getSum(0, 1, sgtTree.m_root) == 1);
    assert(sgtTree.getSum(2, 3, sgtTree.m_root) == 5);   
    assert(sgtTree.getSum(0, 5, sgtTree.m_root) == 15);
    std::cout << "Correct!!\n" << std::endl; 
    
    
    std::cout << "Verify update()" << std::endl; 
    sgtTree.update(1, 2, sgtTree.m_root);
    assert(sgtTree.getSum(0, 1, sgtTree.m_root) == 2);
    assert(sgtTree.getSum(2, 3, sgtTree.m_root) == 5);
    assert(sgtTree.getSum(0, 2, sgtTree.m_root) == 4);
    assert(sgtTree.getSum(0, 5, sgtTree.m_root) == 16);     
    std::cout << "Correct!!\n" << std::endl; 
    return 0;
}
