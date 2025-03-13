#include <iostream>
#include <string>
using namespace std;


class MediaFile {
protected:
    string filePath;
    int size;
public:
    MediaFile(string path, int fileSize) : filePath(path), size(fileSize) {}
    virtual void play() { cout << "Playing media file: " << filePath << endl; }
    virtual void stop() { cout << "Stopping media file: " << filePath << endl; }
    virtual ~MediaFile() {}
};


class VisualMedia : virtual public MediaFile {
protected:
    string resolution;
public:
    VisualMedia(string path, int fileSize, string res) : MediaFile(path, fileSize), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, int fileSize, int rate) : MediaFile(path, fileSize), sampleRate(rate) {}
};

// Derived Classes
class ImageFile : public VisualMedia {
public:
    ImageFile(string path, int fileSize, string res) : VisualMedia(path, fileSize, res), MediaFile(path, fileSize) {}
    void play() override { cout << "Displaying image: " << filePath << " with resolution " << resolution << endl; }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, int fileSize, int rate) : AudioMedia(path, fileSize, rate), MediaFile(path, fileSize) {}
    void play() override { cout << "Playing audio file: " << filePath << " with sample rate " << sampleRate << "Hz" << endl; }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, int fileSize, string res, int rate)
        : MediaFile(path, fileSize), VisualMedia(path, fileSize, res), AudioMedia(path, fileSize, rate) {}
    void play() override { 
        cout << "Playing video: " << filePath << " with resolution " << resolution << " and sample rate " << sampleRate << "Hz" << endl; 
    }
};

int main() {
    MediaFile* mediaFiles[] = {
        new ImageFile("photo.jpg", 500, "1920x1080"),
        new AudioFile("song.mp3", 3000, 44100),
        new VideoFile("movie.mp4", 5000, "1280x720", 48000)
    };

    for (int i = 0; i < 3; i++) {
        mediaFiles[i]->play();
        mediaFiles[i]->stop();
        delete mediaFiles[i];
    }

    return 0;
}
