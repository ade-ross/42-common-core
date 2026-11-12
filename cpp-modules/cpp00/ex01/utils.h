
#ifndef UTILS_H
#define UTILS_H

#include "PhoneBook.hpp"

void print_string_and_pipe(std::string temp);
std::string	ask_wich_contact(const std::string& prompt);
void print_all_contacts(Contact* contacts, int size);
void show_single_contact(Contact* contacts, int i);
void display_contacts(PhoneBook phonebook);

std::string get_validated_phone_number(const std::string& prompt);
std::string get_not_empty_input(const std::string& prompt);
Contact create_contact();
void add_contact(PhoneBook& phonebook);

#endif
