#include <iostream>
#include <fstream>
#include <string>

// bool copyFile(const std::string& srcFile, const std::string& destFile)
// {
// 	std::ifstream src(srcFile.c_str(), std::ios::binary);
// 	std::ofstream dest(destFile.c_str(), std::ios::binary);

// 	if (!src.is_open() || !dest.is_open())
// 	{
// 		std::cout << "Error cannot open the file" << std::endl;
// 		return false;
// 	}

// 	dest << src.rdbuf();
// 	if (!src.good() || !dest.good())
// 	{
// 		std::cout << "Error during file copy" << std::endl;
// 		return false;
// 	}
// 	return true;
// }





bool Copy_Replace(const std::string& srcFile, const std::string& s1, const std::string& s2)
{


	std::ifstream src(srcFile.c_str());
	if (!src.is_open())
		return (std::cerr << "Error cannot open the file" << std::endl, 1);
	if (s1.empty())
		return std::cout << "Error: s1 cannot be empty" << std::endl, false;

	std::string content;
	char c;
	while(src.get(c))
		content += c;
	
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
		//verifier que le fichier de sortie est ouvert pour lecriture acec is_open()
}



int main (int ac, char **av)
{

	if (ac != 4)
		return(std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl,1);

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	// std::ifstream src(filename.c_str());
	// if (!src.is_open())
	// 	return (std::cerr << "Error cannot open the file" << std::endl, 1);

	// std::string content;
	// char c;
	// while(src.get(c))
	// 	content += c;
	if (!Copy_Replace(filename, s1, s2))
		return 1;
	return 0;
}
