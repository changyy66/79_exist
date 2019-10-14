// 79_exist.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

