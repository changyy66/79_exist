// 79_exist.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

ʾ��:

board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]

���� word = "ABCCED", ���� true.
���� word = "SEE", ���� true.
���� word = "ABCB", ���� false.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/word-search
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool existHelper(vector<vector<char>>&  board, string word, int start,vector<vector<bool>>& flag,int m,int n)
{
	if (word.size() == start)
	{
		return true;
	}
	
	if (m==-1&&n==-1)
	{
		for (int i=0;i<board.size();i++)
		{
			for (int j=0;j<board[0].size();j++)
			{
				if (word[start]==board[i][j])
				{
					flag[i][j] = true;
					bool isEnd = existHelper(board, word, start + 1, flag, i, j);
					if (isEnd)return true;
					flag[i][j] = false;
				}
			}
		}
		return false;
	}

	if (m>0 && flag[m - 1][n] == false && board[m - 1][n] == word[start])
	{
		flag[m-1][n] = true;
		bool isEnd = existHelper(board, word, start + 1, flag, m-1, n);
		if (isEnd)return true;
		flag[m-1][n] = false;
	}
	if (n>0 && flag[m][n-1]==false && board[m][n-1]==word[start])
	{
		flag[m][n-1] = true;
		bool isEnd = existHelper(board, word, start + 1, flag, m , n-1);
		if (isEnd)return true;
		flag[m][n-1] = false;
	}
	if (m<board.size()-1&& flag[m + 1][n] == false && board[m + 1][n] == word[start])
	{
		flag[m + 1][n] = true;
		bool isEnd = existHelper(board, word, start + 1, flag, m + 1, n);
		if (isEnd)return true;
		flag[m + 1][n] = false;
	}
	if (n <board[0].size() - 1 && flag[m][n + 1] == false && board[m][n + 1] == word[start])
	{
		flag[m][n + 1] = true;
		bool isEnd = existHelper(board, word, start + 1, flag, m, n + 1);
		if (isEnd)return true;
		flag[m][n + 1] = false;
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0)return false;
	vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
	return existHelper(board, word, 0, flag, -1, -1);
}

int main()
{
	vector<vector<char>> board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	cout << exist(board, "ABCCED");
    return 0;
}

