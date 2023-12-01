#include "../include/Forum.h"

Comment::Comment(string TempId, string TempContent)
    : id(TempId), content(TempContent), current_time(getCurrentTime()){};

string Comment::getCommentTime() { return current_time; }

string Comment::getUserId() { return id; }

string Comment::getContent() { return content; }

void Comment::setTime(string time) { this->current_time = time; }

void Comment::setUserId(string id) { this->id = id; }

void Comment::setContent(string content) { this->content = content; }

ofstream &operator<<(ofstream &output, Comment *comment) {
  if (comment) {
    output << comment->getCommentTime() << endl;
    output << comment->getUserId() << endl;
    output << comment->getContent() << endl;
  }
  return output;
}

Post::Post(string TempUserId, string TempTitle, string TempContent)
    : userid(TempUserId), title(TempTitle), content(TempContent),
      current_time(getCurrentTime()){};

void Post::setId(string id) { this->id = id; }

string Post::getId() { return this->id; }

string Post::getPostUserid() { return userid; }

string Post::getPostTime() { return current_time; }

string Post::getPostTitle() { return title; }

string Post::getPostContent() { return content; }

void Post::setComment(string uid) {
  system("cls");
  string tempContent;
  cout << "\nThe Comment Content : ";
  cin >> tempContent;
  Comment *newComment = new Comment(uid, tempContent);
  comments.push_back(newComment);
  cout << "\nGood job! Press Any key to go back :-)" << endl;
  char r;
  cin >> r;
  return;
}

void Post::showPost() {
  cout << "\n#Post " << getId() << " #" << endl;
  cout << "Post Time : " << getPostTime() << endl;
  cout << "Author : " << getPostUserid() << endl;
  cout << "Title : " << getPostTitle() << endl;
  cout << "Content : " << getPostContent() << endl;
}

void Post::showDetails() {
  system("cls");
  showPost();
  for (int i = 0; i < comments.size(); i++) {
    cout << "\n#Comment " << i << " #" << endl;
    cout << "Comment Time : " << comments[i]->getCommentTime() << endl;
    cout << "Author : " << comments[i]->getUserId() << endl;
    cout << "Content : " << comments[i]->getContent() << endl;
  }
  return;
}

ifstream &operator>>(ifstream &input, Post *post) {
  if (post) {
    string line;
    getline(input, line);
    if (line == "##########") { // 读到一段帖子的开头
      getline(input, line);
      post->id = line;
      getline(input, line);
      post->current_time = line;
      getline(input, line);
      post->userid = line;
      getline(input, line);
      post->title = line;
      getline(input, line);
      post->content = line;
      getline(input, line);
      while (line != "##########" && !input.eof()) { // 读取评论
        Comment *comment = new Comment;
        comment->setTime(line);
        getline(input, line);
        comment->setUserId(line);
        getline(input, line);
        comment->setContent(line);
        post->comments.push_back(comment);
        getline(input, line);
      }
    }
  }
  return input;
}

ofstream &operator<<(ofstream &output, Post *post) {
  if (post) {
    output << "##########" << endl; // 以10个#作为每个帖子的分隔
    output << post->getId() << endl;
    output << post->getPostTime() << endl;
    output << post->getPostUserid() << endl;
    output << post->getPostTitle() << endl;
    output << post->getPostContent() << endl;
    for (int i = 0; i < post->comments.size(); i++) // 评论也跟在帖子后面
      output << post->comments[i];
  }
  return output;
}

// Forum::Forum() : post_id(0), post_count(0), user_id(0){};

void Forum::forumMenu() {
  readPost();
  system("cls");
  cout << "========== Welcome to Study Forum ==========" << endl;
  if (!posts.empty()) {
    for (Post *post : posts) {
      post->showPost();
    }
  } else {
    cout << "The forum is empty. Try to create the first post!" << endl;
  }
  cout << "================== The end ==================" << endl;
  int ret = 0;
  do {
    cout << "Press\n1. To view details of one Post" << endl;
    cout << "2. To start a new Post" << endl;
    cout << "3. To back to the last menu" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: {
      int post_id;
      cout << "\nPlease enter the post id : " << endl;
      cin >> post_id;
      Post *post = findPost(post_id);
      if (post) {
        post->showDetails();
        cout << "Press [1] to send Comment and Press Other key to go back :-"
             << endl;
        char r;
        cin >> r;
        if (r == '1') {
          post->setComment(this->user_id);
        }
      } else {
        cout << "Invalid Post Id! Press [1] to try again" << endl;
        cin >> ret;
      }
    } break;
    case 2:
      setPost();
      break;
    case 3:
      break;
    default:
      cout << "INVALID CHOICE" << endl;
      cout << "press [1] to try again, else back to the menu";
      cin >> ret;
      while (cin.fail()) {
        cout << "\nIllegal input! Please enter an Integer:" << endl;
        cin.clear();
        cin.ignore();
        cin >> ret;
      }
      break;
    }
  } while (ret == 1);
  return;
}

Post *Forum::findPost(int postId) {
  string id = to_string(postId);
  for (Post *post : posts) {
    if (post->getId() == id) {
      return post;
    }
  }
  return nullptr;
}

void Forum::setUserId(string userId) { this->user_id = userId; }

void Forum::setPost() {
  system("cls");
  char tempTitle[256], tempContent[256];
  cout << "\nThe Post Title : ";
  // cin.getline(tempTitle, 256);
  cin >> tempTitle;
  cout << "\nThe Post Content : ";
  cin.clear();
  cin.sync();
  cin.getline(tempContent, 256);
  Post *newPost = new Post(user_id, tempTitle, tempContent);
  posts.push_back(newPost);
  cout << "\nGood job! Press Any key to go back :-)" << endl;
  char r;
  cin >> r;
  return;
}

void Forum::deletePost(Forum *forum) {}

void Forum::savePosts() {
  ofstream writePost("forum/posts.txt");
  for (Post *post : posts) {
    writePost << post;
  }
  return;
}

void Forum::readPost() {
  ifstream readPost;
  readPost.open("forum/posts.txt");
  while (!readPost.eof()) {
    Post *post = new Post;
    readPost >> post;
    if (post->getPostTitle().empty())
      continue;
    posts.push_back(post);
    post_count++;
  }
  readPost.close();
  return;
}

string getCurrentTime() {
  /*auto currentTimePoint = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(currentTimePoint); */
  // 转换时间类型，后面还要转成localtime(&currentTime)，过于麻烦

  time_t now = time(nullptr);
  tm *curr_tm = localtime(&now);

  string timeString(20, '\0'); // 预分配足够的空间
  strftime(&timeString[0], timeString.size(), "%Y-%m-%d %H:%M:%S",
           curr_tm); // strftime : 根据 format
                     // 中定义的格式化规则，格式化结构 curr_tm
                     // 表示的时间，并把它存储在 timeString 中
  return timeString;
}
