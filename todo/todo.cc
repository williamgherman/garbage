#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
#include <cstdlib>
#include <cstring>

void printhelp();
void listcontents();
void addline();
std::list<std::string> loadtasks();
void removeitem(const char *);
void writetofile(const std::list<std::string> &);


void printhelp()
{
    std::cout << "USAGE: todo [OPTION] or todo [COMMAND]\n"
                 "OPTIONS:\n"
                 "  -h, --help      Prints this help menu\n"
                 "  -v, --version   Prints version info\n"
                 "COMMANDS:\n"
                 "  ls              Lists current entries\n"
                 "  rm n            Removes the nth entry\n"
                 "  add             Adds new entry\n"
              << std::endl;
    std::exit(EXIT_SUCCESS);
}

void listcontents()
{
    std::ifstream in("todo.dat");
    std::string line;
    int order = 1;

    if (!in) {
        std::cerr << "Error: file could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    while (std::getline(in, line)) {
        std::cout << order << ". " << line << std::endl;
        ++order;
    }
}

std::list<std::string> loadtasks()
{
    std::ifstream in("todo.dat");
    std::string line;
    std::list<std::string> tasks;
    if (!in) {
        std::cerr << "Error: file could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (std::getline(in, line))
        tasks.push_back(line);
    return tasks;
}

void addline()
{
    std::list<std::string> tasks = loadtasks();
    std::list<std::string>::size_type pos;
    std::string line;

    std::cout << "Input entry: " << std::flush;
    std::getline(std::cin, line);
    std::cout << "Enter position in to-do list (defaults to end): " 
              << std::flush;
    std::cin >> pos;
    pos--;

    std::list<std::string>::iterator it = tasks.begin();
    if (pos >= tasks.size())
        it = tasks.end();
    else
        std::advance(it, pos);
    tasks.insert(it, line);

    writetofile(tasks);
    listcontents();
}

void removeitem(const char *item)
{
    std::list<std::string> tasks = loadtasks();
    int pos = std::stoi(std::string(item)) - 1;
    std::list<std::string>::iterator it = tasks.begin();
    std::advance(it, pos);
    if (it != tasks.end())
        tasks.erase(it);
    else
        std::cerr << "Error: enter valid element number to remove" << std::endl;
    writetofile(tasks);
    listcontents();
}

void writetofile(const std::list<std::string> &tasks)
{
    std::ofstream out("todo.dat");
    if (!out) {
        std::cerr << "Error: file could not be written." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (const auto &task : tasks)
        out << task << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        listcontents();
    for (std::size_t i = 1; i < argc; i++) {
        if (!std::strcmp(argv[i], "-v") || !std::strcmp(argv[i], "--version")) {
            std::cout << "Todo version 2019-09-07" << std::endl;
            return EXIT_SUCCESS;
        }
        else if (!std::strcmp(argv[i], "ls"))
            listcontents();
        else if (!std::strcmp(argv[i], "add"))
            addline();
        else if (!std::strcmp(argv[i], "-h") || !std::strcmp(argv[i], "--help"))
            printhelp();
        else if (!std::strcmp(argv[i], "rm")) {
            if (i < argc - 1) {
                removeitem(argv[i+1]);
                ++i;
            } else
                std::cerr << "USAGE: todo rm [number]" << std::endl;
        } else {
            std::cerr << "Error: option " << argv[i] << " not recognized."
                      << std::endl;
            return EXIT_FAILURE;
        }
    }
}
