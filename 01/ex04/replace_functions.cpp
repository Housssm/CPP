#include "replace.hpp"

bool Copy_Replace(const std::string& srcFile, const std::string& s1, const std::string& s2)
{
	std::ifstream src(srcFile.c_str());
	if (!src.is_open())
		return (std::cerr << "Error cannot open the file" << std::endl, false);
	if (s1.empty())
		return std::cout << "Error: s1 cannot be empty" << std::endl, false;
	std::string content;
	char c;
	while(src.get(c))
		content += c;
	src.close();
	std::string result;
	size_t		start_pos = 0;
	size_t		found_pos = content.find(s1, start_pos);
	while(found_pos != std::string::npos)
	{
		result.append(content, start_pos, found_pos - start_pos);
		result.append(s2);
		start_pos = found_pos + s1.length();
		found_pos = content.find(s1, start_pos);
	}
	result.append(content, start_pos, content.length() - start_pos);
	std::ofstream dest((srcFile + ".replace").c_str());
	if (!dest.is_open())
		return (std::cout << "Error cannot create the destination file" << std::endl, false);
	dest << result; 
	return true;
}