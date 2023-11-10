#include<bits/stdc++.h>
using namespace std;

class Media {
public:
    string title;
    int views;

    virtual void showInfo() {
        cout << "Title: " << title << ", Views: " << views << endl;
    }
};

class Video : public Media {
public:
    string videoID;
    string uploader;

    void updateViews() {
        views++;
    }

    void showInfo() override {
        cout << "Video ID: " << videoID << ", Title: " << title << ", Views: " << views << ", Uploader: " << uploader << endl;
    }
};

class User {
public:
    string userID;
    string username;

    void watchVideo(Video& video) {
        video.updateViews();
    }
};

int main() {
    Video video1;
    video1.videoID = "abc123";
    video1.title = "Cool Video";
    video1.views = 1000;
    video1.uploader = "User123";

    User user1;
    user1.userID = "user123";
    user1.username = "Ashish";

    user1.watchVideo(video1);

    video1.showInfo();
    return 0;
}
