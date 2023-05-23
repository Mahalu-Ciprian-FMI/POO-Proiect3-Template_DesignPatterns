#include "clase.h"
int main()
{
	/*std::string current_month;
	int prima;
	int current_month_int;
	int current_an;
	std::cout << "Introduceti toate datele folosing litere mici!\n";
	std::cout << "Introduceti luna curenta: ";
	std::cin >> current_month;
	std::cout << "Introduceti anul curent: ";
	std::cin >> current_an;
	if (1)
	{
		if (current_month == "ianuarie")
			current_month_int = 1;
		if (current_month == "februarie")
			current_month_int = 2;
		if (current_month == "martie")
			current_month_int = 3;
		if (current_month == "aprilie")
			current_month_int = 4;
		if (current_month == "mai")
			current_month_int = 5;
		if (current_month == "iunie")
			current_month_int = 6;
		if (current_month == "iulie")
			current_month_int = 7;
		if (current_month == "august")
			current_month_int = 8;
		if (current_month == "septembrie")
			current_month_int = 9;
		if (current_month == "octombrie")
			current_month_int = 10;
		if (current_month == "noiembrie")
			current_month_int = 11;
		if (current_month == "decembrie")
			current_month_int = 12;
	}
	std::cout << "Introduceti bonusul: ";
	std::cin >> prima;
	std::vector<Angajat*> v;
	std::cout << "Introduceti numarul de angajati al firmei: ";
	int angajare;
	std::cin >> angajare;
	while (angajare)
	{
		int tip;
		std::cout << "Introduceti tipul contractului 1-Permanent 2-Part_Time: ";
		std::cin >> tip;
		try
		{
			if (tip == 1 || tip == 2)
			{
				angajare--;
				if (tip == 1)
				{
					v.push_back(new Permanent());
				}
				else
				{
					v.push_back(new Part_Time());
				}
			}
			else
				throw(tip);
		}
		catch (int wrongnumber)
		{
			std::cout << "Numarul " << wrongnumber << " a fost introdus, in loc de 1 sau 2.\n";
		}
	}
	std::vector<Permanent> v1;
	std::vector<Part_Time> v2;
	for (auto p = v.begin();p != v.end();p++)
	{
		if (typeid(**p) == typeid(Permanent))
			v1.push_back(*dynamic_cast<Permanent*>(*p));
		else
			v2.push_back(*dynamic_cast<Part_Time*>(*p));
	}
	for (auto p = v1.begin();p != v1.end();p++)
	{
		try
		{
			if (p->get_nr_minori() < 0)
				throw(p->get_nr_minori());
			else
				if (p->get_nr_minori() == 0)
				{
					float a = p->get_salariu() + prima;
					p->set_salariu(a);
				}
				else
				{
					float a = p->get_salariu() + (p->get_nr_minori() * (2020 - p->get_data_angajare().get_an()) * prima / 100) + prima;
					p->set_salariu(a);
				}
		}
		catch (int nr_copii)
		{
			std::cout << "\nO persoana nu poate avea un numar de copii negativ, precum: " << nr_copii << "\n";
		}
	}
	int b = NULL;
	for (auto p = v2.begin();p != v2.end();p++)
	{
		try
		{
			if (p->get_final_contract().get_zi() > 31 || p->get_final_contract().get_zi() < 1)
				throw(p->get_final_contract().get_zi());
			else
			{
				if (1)
				{
				if (p->get_final_contract().get_luna() == "ianuarie")
					b = 1;
				if (p->get_final_contract().get_luna() == "februarie")
					b = 2;
				if (p->get_final_contract().get_luna() == "martie")
					b = 3;
				if (p->get_final_contract().get_luna() == "april")
					b = 4;
				if (p->get_final_contract().get_luna() == "mai")
					b = 5;
				if (p->get_final_contract().get_luna() == "iunie")
					b = 6;
				if (p->get_final_contract().get_luna() == "iulie")
					b = 7;
				if (p->get_final_contract().get_luna() == "august")
					b = 8;
				if (p->get_final_contract().get_luna() == "septembrie")
					b = 9;
				if (p->get_final_contract().get_luna() == "octombrie")
					b = 10;
				if (p->get_final_contract().get_luna() == "noiembrie")
					b = 11;
				if (p->get_final_contract().get_luna() == "decembrie")
					b = 12;
				}
				if (b>current_month_int && p->get_final_contract().get_an()==current_an || p->get_final_contract().get_an()>current_an)
				{
					float a = p->get_salariu() + prima;
					p->set_salariu(a);
				}
				else
				{
					
					if (p->get_final_contract().get_an() == current_an)
					{
						float a = p->get_salariu() + 0.75 * prima;
						p->set_salariu(a);
					}
				}
			}
		}
		catch (int zi)
		{
			std::cout << "O luna nu poate avea " << zi << " zile";
		}
	}

	for (auto p = v1.begin();p != v1.end();p++)
	{
		p->afisare();
		std::cout << "\n";
	}
	for (auto p = v2.begin();p != v2.end();p++)
	{
		std::cout << "\n";
		if (p->get_final_contract().get_an() >= 2020)
			p->afisare();
		else
			//std::cout << " Numele fostului angajat este: " << p->get_nume() << " " << p->get_prenume();
		std::cout << "\n";
	}*/
	builder_perm x;
	builder_part y;
	Permanent x1;
	Part_Time y1;
	x1 = x.name("G").pname("T").salary(3000).emp_date(Data(1, "mai", 2022)).nr_children(2).finish();
	y1 = y.name("T").pname("G").salary(1500).emp_date(Data(2, "iunie", 2019)).ore_luc(4).fire_date(Data(3, "august", 2023)).finish();
	x1.afisare();
	y1.afisare();

	std::cout << " \n";

	Part_Time y2, y3, y4;
	y2 = y.name("A").pname("C").salary(5250).emp_date(Data(6, "septembrie", 2022)).ore_luc(4).fire_date(Data(19, "decembrie", 2023)).finish();
	y3 = y.name("P").pname("L").salary(9000).emp_date(Data(18, "noiembrie", 2020)).ore_luc(4).fire_date(Data(5, "decembrie", 2021)).finish();
	y4 = y.name("R").pname("S").salary(2300).emp_date(Data(20, "august", 2019)).ore_luc(4).fire_date(Data(31, "ianuarie", 2021)).finish();
	connection_pool obj1;
	try
	{
		//Part_Time c1 = obj1.get_conn();
		Part_Time data1 = obj1.fetch_info(y1);
		data1.afisare();
		//Part_Time c2 = obj1.get_conn();
		Part_Time data2 = obj1.fetch_info(y2);
		data2.afisare();
		//Part_Time c3 = obj1.get_conn();
		Part_Time data3 = obj1.fetch_info(y3);
		data3.afisare();
	}
	catch (std::runtime_error& err) { std::cout << err.what() << "\n"; }

	std::cout << " \n";
	connection_pool obj2;
	try
	{
		Part_Time c1 = obj2.get_conn();
		Part_Time data1 = obj2.fetch_info(y4);
		data1.afisare();
		Part_Time c2 = obj2.get_conn();
		Part_Time data2 = obj2.fetch_info(y3);
		data2.afisare();
		Part_Time c3 = obj2.get_conn();
		Part_Time data3 = obj2.fetch_info(y2);
		data3.afisare();
		Part_Time c4 = obj2.get_conn();
		Part_Time data4 = obj2.fetch_info(y1);
		data4.afisare();
	}
	catch (std::runtime_error& a) { std::cout << a.what() << "\n"; }
	return 0;
}