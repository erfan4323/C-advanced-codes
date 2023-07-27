#include <iostream>

using namespace std;



template<typename T>
class Queue {
private:
    const int size = 5;
    int front, rear;
    T* qArr;

public:
    Queue() {
        qArr = new T[size];
        front = rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enQueue(const T& value) {
        if (isFull()) {
            cout << "Queue is full! The element can't fit in the queue." << endl;
        }
        else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % size;
            qArr[rear] = value;
        }
    }

    T deQueue() {
        T element;
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }
        else {
            element = qArr[front];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % size;
            }
        }
        return element;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }
        return qArr[front];
    }

    void display() {
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << qArr[i] << " ";
            i = (i + 1) % size;
        }
        cout << qArr[i] << endl;
    }

    ~Queue() {
        delete[] qArr;
    }
};

class Song {
    char category;
    int requests;
    int duration;

    Song(char c, int r, int d) : category(c), requests(r), duration(d) {}
};

class MusicProgram {
private:
    Queue<Song> categories[4];

public:
    void addSong(const string& songData) {
        char category = songData[0];
        int requests = stoi(songData.substr(2, songData.find(':', 2) - 2));
        int duration = stoi(songData.substr(songData.find(':', 2) + 1));

        int categoryIndex = getCategoryIndex(category);
        if (categoryIndex != -1) {
            Song song(category, requests, duration);
            categories[categoryIndex].enQueue(song);
        }
    }

    void playSongs() {
        int totalTime = 0;

        while (!allCategoriesEmpty() && totalTime < 60) {
            Song selectedSong = selectSong();
            totalTime += selectedSong.duration;
            if (totalTime <= 60) {
                cout << "Playing song: " << selectedSong.category << " - Duration: " << selectedSong.duration << " seconds" << endl;
            }
        }
    }

    void printStatistics() {
        int categoryRequests[4] = { 0 };
        int totalRequests = 0;

        for (int i = 0; i < 4; i++) {
            Queue<Song> categoryQueue = categories[i];
            while (!categoryQueue.isEmpty()) {
                Song song = categoryQueue.deQueue();
                categoryRequests[i] += song.requests;
                totalRequests += song.requests;
            }
        }

        cout << "Category Statistics:" << endl;
        for (int i = 0; i < 4; i++) {
            double percentage = 0.0;
            if (totalRequests > 0)
                percentage = static_cast<double>(categoryRequests[i]) / totalRequests * 100;
            cout << "Category " << getCategoryName(i) << ": " << categoryRequests[i] << " requests (" << percentage << "%)" << endl;
        }
    }

private:
    int getCategoryIndex(char category) {
        switch (category) {
        case 'S':
            return 0;
        case 'P':
            return 1;
        case 'K':
            return 2;
        case 'M':
            return 3;
        default:
            return -1;
        }
    }

    string getCategoryName(int index) {
        switch (index) {
        case 0:
            return "Traditional";
        case 1:
            return "Pop";
        case 2:
            return "Classical";
        case 3:
            return "Local";
        default:
            return "";
        }
    }

    bool allCategoriesEmpty() {
        for (int i = 0; i < 4; i++) {
            if (!categories[i].isEmpty())
                return false;
        }
        return true;
    }

    Song selectSong() {
        int maxRequests = 0;
        int selectedCategory = -1;

        for (int i = 0; i < 4; i++) {
            if (!categories[i].isEmpty()) {
                Song song = categories[i].peek();
                if (song.requests > maxRequests) {
                    maxRequests = song.requests;
                    selectedCategory = i;
                }
            }
        }

        if (selectedCategory != -1) {
            Song selectedSong = categories[selectedCategory].deQueue();
            return selectedSong;
        }

        return Song(' ', 0, 0);
    }
};

int main() {
    MusicProgram program;
    program.addSong("S:8:90");
    program.addSong("P:6:120");
    program.addSong("K:2:180");
    program.addSong("M:5:300");

    program.playSongs();
    program.printStatistics();

    return 0;
}
