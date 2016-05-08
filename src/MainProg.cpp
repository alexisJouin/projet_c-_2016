
#include <cmath>
#include <gtkmm.h>
#include <iostream>

using namespace std;

class UiBidon {
    private:
        Gtk::Main _kit;
        Gtk::Window _window;
        Gtk::DrawingArea _dessin;
    public:
        UiBidon(int argc, char ** argv);
        void run();
        bool afficher(GdkEventExpose * event);
        bool cliquer(GdkEventButton * event);
        void displayMessage(const std::string & title, const std::string & message);
};

int main(int argc, char ** argv) {

    // verifie la ligne de commande
    if (argc != 4) {
        cout << "usage: " << argv[0] << " <ui> <joueur1> <joueur2>" << endl;
        exit(-1);
    }
    const string strUi = argv[1];
    const string strJoueur1 = argv[2];
    const string strJoueur2 = argv[3];

    UiBidon ui(argc, argv);
    ui.run();

    return 0;
}

UiBidon::UiBidon(int argc, char ** argv):
    _kit(argc, argv)
{
    _dessin.signal_expose_event().connect(
            sigc::mem_fun(*this, &UiBidon::afficher));

    _dessin.add_events(Gdk::BUTTON_PRESS_MASK);
    _dessin.signal_button_press_event().connect( 
            sigc::mem_fun(*this, &UiBidon::cliquer));

    _window.add(_dessin);
    _window.set_title("42 vainc");
    _window.set_default_size(800, 100);
    _window.show_all();
}

void UiBidon::run() {
    _kit.run(_window);
}

bool UiBidon::afficher(GdkEventExpose*) { 

    // récupère le contexte cairo
    Glib::RefPtr<Gdk::Window> window = _dessin.get_window();
    Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();
    int width = window->get_width();
    int height = window->get_height();

    // remplit le fond
    context->set_source_rgb(0.8, 0.7, 0.4);
    context->rectangle(0, 0, width, height);
    context->fill();
    context->stroke();

    // affiche un nombre
    context->set_source_rgb(0.0, 0.0, 0.0);
    context->set_font_size(24);
    // texte à afficher
    std::string texte = "42";
    // calcule la taille du texte
    Cairo::TextExtents extents;
    context->get_text_extents(texte, extents);
    // affiche le texte au centre
    int x = width/2 - extents.width/2;
    int y = height/2 + extents.height/2;
    context->move_to(x, y);
    context->show_text(texte);
    context->stroke();

    // entoure le texte affiché
    int radius = std::min(width, height) / 4;
    context->save();
    context->translate(width/2, height/2);
    context->scale(radius, radius);
    context->arc(0.0, 0.0, 1.0, 0.0, 2 * M_PI);
    context->restore();
    context->stroke();

    return true;
}

bool UiBidon::cliquer(GdkEventButton * ) {

    // affiche un message bidon
    displayMessage("Message", "Bravo, vous avez réussi à cliquer !");

    // met à jour l'interface
    _dessin.get_window()->invalidate(false);

    return true;
}


void UiBidon::displayMessage(const std::string & title, const std::string & message) {
    Glib::ustring uTitle(title.c_str());
    Glib::ustring uMessage(message.c_str());
    Gtk::MessageDialog dialog(_window, uMessage);
    dialog.set_title(uTitle);
    dialog.run();
}
 

