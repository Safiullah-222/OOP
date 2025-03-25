class Media {
    protected:
        string title;
        string publisher;
        string uniqueID;
        string publicationDate;
        bool checkedOut;
    
    public:
        Media(string t, string p, string id, string date)
            : title(t), publisher(p), uniqueID(id), publicationDate(date), checkedOut(false) {}
    
        virtual void displayInfo() {
            cout << "Title: " << title << "\nPublisher: " << publisher
                 << "\nPublication Date: " << publicationDate << endl;
        }
    
        void checkOut() {
            checkedOut = true;
        }
    
        void returnItem() {
            checkedOut = false;
        }
    };
    
    class Book : public Media {
        string author;
        string isbn;
        int pageCount;
    
    public:
        Book(string t, string p, string id, string date, string auth, string ib, int pages)
            : Media(t, p, id, date), author(auth), isbn(ib), pageCount(pages) {}
    
        void displayInfo() override {
            Media::displayInfo();
            cout << "Author: " << author << "\nISBN: " << isbn 
                 << "\nPages: " << pageCount << endl;
        }
    };
    
    class DVD : public Media {
        string director;
        int duration; // minutes
        string rating;
    
    public:
        DVD(string t, string p, string id, string date, string dir, int dur, string rate)
            : Media(t, p, id, date), director(dir), duration(dur), rating(rate) {}
    
        void displayInfo() override {
            Media::displayInfo();
            cout << "Director: " << director << "\nDuration: " << duration 
                 << " mins\nRating: " << rating << endl;
        }
    };