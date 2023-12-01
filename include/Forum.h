#ifndef _FORUM_
#define _FORUM_
// #include <chrono>
#include <ctime>
// #include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Post;
class Comment;
class User;

string getCurrentTime(); // 以string形式返回当前时间

class Forum {
private:
  vector<Post *> posts; // 储存所有帖子

  int post_id; // 标记正在查看的帖子id

  int post_count; // 统计帖子数量为新帖生成id，为了防止前面帖子删帖导致生成重复id，因此只会增加不会减少（或者说记录最新的帖子id去到了多少）

  string user_id;

public:
  // Forum();

  void forumMenu(); // 论坛系统初始化：读帖子文件并显示整体界面

  Post *findPost(int postId);

  void setUserId(string userId);

  void setPost(); // 发帖函数

  void deletePost(Forum *forum); // 删帖函数

  void savePosts(); // 向文件中保存帖子

  void readPost(); // 从文件中读取帖子信息
};

class Post {
private:
  string id;           // 帖子id
  string userid;       // 发帖者id
  string title;        // 帖子标题
  string content;      // 帖子内容
  string current_time; // 发帖时间

public:
  vector<Comment *> comments; // 评论容器

  Post(){};

  Post(string TempUserId, string TempTitle, string TempContent);

  void setId(string id);

  string getId(); // 返回帖子id

  string getPostUserid(); // 返回发帖者

  string getPostTime(); // 返回发帖时间

  string getPostTitle(); // 返回帖子题目

  string getPostContent(); // 返回帖子内容

  void setComment(string uid); // 发送评论

  void showPost();

  void showDetails();

  friend ifstream &operator>>(ifstream &input,
                              Post *post); // 重载流运算符使其可以写入对象

  friend ofstream &operator<<(ofstream &output, Post *post); // 写出到文件
};

class Comment {
private:
  string id;           // 评论者id
  string content;      // 评论内容
  string current_time; // 评论时间
public:
  Comment(){};

  Comment(string TempId, string TempContent);

  string getCommentTime(); // 返回评论时间

  string getUserId(); // 返回评论人id

  string getContent(); // 返回评论内容

  void setTime(string time);

  void setUserId(string id);

  void setContent(string content);

  friend ofstream &operator<<(ofstream &output, Comment *comment);
  // 写出到文件，用法如下：
  // ofstream com("comments.txt");
  // com << &comment ...
};

#endif