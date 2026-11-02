
#include "ScalarConverter.hpp"
#include "Serializer.hpp"

int main()
{
	Data		data;
	uintptr_t	raw;
	Data*		ptr;

	data.name = "bob";
	data.value = 42;

	std::cout << "Original ptr  : " << &data << std::endl;
	std::cout << "Original name : " << data.name << std::endl;
	std::cout << "Original val  : " << data.value << std::endl;

	std::cout << "----------------------------------" << std::endl;

	// serialize
	raw = Serializer::serialize(&data);
	std::cout << "Serialized (raw) : " << raw << std::endl;

	// deserialize
	ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr : " << ptr << std::endl;

	std::cout << "----------------------------------" << std::endl;

	// verif des adresses et des valeurs
	if (ptr == &data)
		std::cout << "OK : Adresses identiques !" << std::endl;
	else
		std::cout << "KO : Probleme de cast..." << std::endl;

	std::cout << "Restored name : " << ptr->name << std::endl;
	std::cout << "Restored val  : " << ptr->value << std::endl;

	return 0;
}