#include <iostream>
#include <poppler-document.h>
#include <poppler-page.h>
using namespace std;

int main() {
    auto doc = poppler::document::load_from_file("slate_ip.pdf");
    if (!doc) {
        cerr << "Could not open PDF." << endl;
        return 1;
    }

    cout << "Pages: " << doc->pages() << endl;
    unique_ptr<poppler::page> page(doc->create_page(0));
    cout << "Text:\n" << page->text().to_latin1() << endl;
    return 0;
}
