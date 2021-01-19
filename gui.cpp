#include "gui.h"
#include "codewindow.h"

Gui::Gui()
{
    // Gruppe : Klasse definieren
        name = new QLineEdit;
        motherClass = new QLineEdit;

        QFormLayout *definitionLayout = new QFormLayout;
        definitionLayout->addRow("&Name :", name);
        definitionLayout->addRow("&Mother class:", motherClass);

        QGroupBox *groupDefinition = new QGroupBox("Definition of the class");
        groupDefinition->setLayout(definitionLayout);


        // Gruppe : Optionen

        protections = new QCheckBox("&Protect the header against multiple inclusions");
        protections->setChecked(true);
        generateConstructor = new QCheckBox("Generate a default &constructor");
        generateDestructor = new QCheckBox("Generate a &destructor");

        QVBoxLayout *optionsLayout = new QVBoxLayout;
        optionsLayout->addWidget(protections);
        optionsLayout->addWidget(generateConstructor);
        optionsLayout->addWidget(generateDestructor);

        QGroupBox *groupOptions = new QGroupBox("Options");
        groupOptions->setLayout(optionsLayout);



        // Gruppe : Kommentaren

        autor = new QLineEdit;
        date = new QDateEdit;
        date->setDate(QDate::currentDate());
        role = new QTextEdit;

        QFormLayout *commentairesLayout = new QFormLayout;
        commentairesLayout->addRow("&Autor :", autor);
        commentairesLayout->addRow("&Creation date :", date);
        commentairesLayout->addRow("&Role of the class :", role);

        groupComment = new QGroupBox("Add comments");
        groupComment->setCheckable(true);
        groupComment->setChecked(false);
        groupComment->setLayout(commentairesLayout);


        // Layout : untere Schalten (erzeugen, gehen...)
        generate = new QPushButton("&Generate !");
        quit = new QPushButton("&Quit");

        QHBoxLayout *boutonsLayout = new QHBoxLayout;
        boutonsLayout->setAlignment(Qt::AlignRight);

        boutonsLayout->addWidget(generate);
        boutonsLayout->addWidget(quit);


        // Fenstereigenschaften definieren

        QVBoxLayout *layoutPrincipal = new QVBoxLayout;
        layoutPrincipal->addWidget(groupDefinition);
        layoutPrincipal->addWidget(groupOptions);
        layoutPrincipal->addWidget(groupComment);
        layoutPrincipal->addLayout(boutonsLayout);

        setLayout(layoutPrincipal);
        setWindowTitle("Class Generator");
        setWindowIcon(QIcon("icone.png"));
        resize(400, 450);

    //  signals und slots
        connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
        connect(generate, SIGNAL(clicked()), this, SLOT(generateCode()));

}
void Gui::generateCode()
{
    // Der Name muss mindestens ausgefüllt werden
    if (name->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Please enter at least one class name");
        return; // stopp
    }

    //
    QString code;

    // Codenerzeugung
    if (groupComment->isChecked()) // Kommentare hinzufügen
        {
            code += "/*\nAutor : " + autor->text() + "\n";
            code += "Creation date : " + date->date().toString() + "\n\n";
            code += "Role :\n" + role->toPlainText() + "\n*/\n\n\n";
        }

        if (protections->isChecked())
        {
            code += "#ifndef HEADER_" + name->text().toUpper() + "\n";
            code += "#define HEADER_" + name->text().toUpper() + "\n\n\n";
        }

        code += "class " + name->text();

        if (!motherClass->text().isEmpty())
        {
            code += " : public " + motherClass->text();
        }

        code += "\n{\n    public:\n";
        if (generateConstructor->isChecked())
        {
            code += "        " + name->text() + "();\n";
        }
        if (generateDestructor->isChecked())
        {
            code += "        ~" + name->text() + "();\n";
        }
        code += "\n\n    protected:\n";
        code += "\n\n    private:\n";
        code += "};\n\n";

        if (protections->isChecked())
        {
            code += "#endif\n";
        }


    // Fenster zur Anzeige des Codes
    codeWindow *windowCode = new codeWindow(code, this);
    windowCode->exec();
}
