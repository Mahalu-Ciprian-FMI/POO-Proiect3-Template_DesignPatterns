#include "clase.h"; // fara in caz de template?
//template<typename T>
Data::Data()
{
	//std::cout << "Introduceti ziua:";
	//std::cin >> zi;
	//std::cout << "Introduceti luna:";
	//std::cin >> luna;
	//std::cout << "Introduceti anul:";
	//std::cin >> an;
}
//template<typename T>  !!Data<T> instead
Data::Data(int zi1,std::string luna1, int an1)
	:zi(zi1), luna(luna1), an(an1)
{
}
//template<typename T>  !!Data<T> instead
Data::Data(const Data& data)
{
	zi = data.zi;
	luna = data.luna;
	an = data.an;
}
//template<typename T>  !!Data<T> instead
Data::~Data()
{
}
//template<typename T>  !!Data<T> instead
int Data::get_zi()
{
	return zi;
}
//template<typename T>  !!Data<T> instead
std::string Data::get_luna()
{
	return luna;
}
//template<typename T>  !!Data<T> instead
int Data::get_an()
{
	return an;
}
//template<typename T>  !!Data<T> instead
void Data::operator=(const Data& obj)
{
	zi = obj.zi;
	luna = obj.luna;
	an = obj.an;
}
//template<typename T>  !!Data<T> instead
std::ostream& operator<<(std::ostream& out, Data& obj)
{
	std::cout << obj.zi << " " << obj.luna << " " << obj.an;
	return out;
}
std::istream& operator>>(std::istream& in, Data& obj)
{
	std::cout << "Introduceti ziua,luna si anul: ";
	in >> obj.zi >> obj.luna >> obj.an;
	return in;
}
//template<typename T>  !!Data<T> instead
void Data::set_zi(int z)
{
	zi = z;
}
//template<typename T>  !!Data<T> instead
void Data::set_luna(std::string l)
{
	luna = l;
}
//template<typename T>  !!Data<T> instead
void Data::set_an(int a)
{
	an = a;
}

const char* Expired::motive()
{
	return "Contractul acestui fost angjat s-a terminat inainte de anul 2020\n";
}

void Angajat::citire()
{
	std::cout << "Introduceti numele,prenumele si salariul: ";
	std::cin >> nume;
	//std::cout << "Introduceti prenumele:";
	std::cin >> prenume;
	//std::cout << "Introduceti salariul:";
	std::cin >> salariu;
	std::cout << "Introduceti data angajarii:";
	std::cin >> data_angajare;
}
void Angajat::afisare()
{
	std::cout << nume << " " << prenume << " " << salariu << " " << data_angajare << " ";
}
void Part_Time::citire()
{
	Angajat::citire();
	std::cout << "Introduceti numarul de ore lucrate zilnic:";
	std::cin >> nr_ore_zi;
	std::cout << "Introduceti Data finalizarii contractului:";
	std::cin >> final_contract;
	try
	{
		if (final_contract.get_an() < 2020)
			throw Expired();
	}
	catch (Expired& object)
	{
		std::cout << "\n !!!!   ";
		std::cout << object.motive();
	}
}
void Part_Time::afisare()
{
	Angajat::afisare();
	std::cout << nr_ore_zi << " " << final_contract << std::endl;
}
void Permanent::citire()
{
	Angajat::citire();
	std::cout << "Introduceti numarul de copii:";
	std::cin >> nr_minori_intretinere;
}
void Permanent::afisare()
{
	Angajat::afisare();
	std::cout << nr_minori_intretinere << std::endl;
}
Part_Time::Part_Time()
{
	//Part_Time::citire();
}
Permanent::Permanent()
{
	//Permanent::citire();
}
std::string Angajat::get_nume()
{
	return nume;
}
std::string Angajat::get_prenume()
{
	return prenume;
}
float Angajat::get_salariu()
{
	return salariu;
}
Data Angajat::get_data_angajare()
{
	return data_angajare;
}
void Angajat::set_nume(std::string n)
{
	nume = n;
}
void Angajat::set_prenume(std::string p)
{
	prenume = p;
}
void Angajat::set_salariu(float s)
{
	salariu = s;
}
//Data<T> instead? (as parameter) + template<typename T>
void Angajat::set_data_angajare(Data d)
{
	data_angajare = d;
}
int Part_Time::get_nr_ore_zi()
{
	return nr_ore_zi;
}

Data Part_Time::get_final_contract()
{
	return final_contract;
}
void Part_Time::set_nr_ore_zi(int nr)
{
	nr_ore_zi = nr;
}
//Data<T> instead? (as parameter) + template<typename T>
void Part_Time::set_final_contract(Data final)
{
	final_contract = final;
}
int Permanent::get_nr_minori()
{
	return nr_minori_intretinere;
}
void Permanent::set_nr_minori(int nr)
{
	nr_minori_intretinere = nr;
}
Angajat::~Angajat(){}
Permanent::~Permanent(){}
void Part_Time::open() { pool = true; }
bool  Part_Time::free() const {return !pool; }
void  Part_Time::close() { pool = false; }
Part_Time::~Part_Time() { close(); }
Part_Time connection_pool::get_conn()
{
	for (auto conn :connections)
		if (conn.free())
		{
			conn.open();
			return conn;
		}
	throw std::runtime_error("Can't have more than 3 open connections simultaneously");
}
Part_Time connection_pool::fetch_info(Part_Time x)
{
	return x;
}
builder_perm& builder_perm::name(std::string n) { p.nume = n; return *this; }
builder_perm& builder_perm::pname(std::string pn) { p.prenume = pn; return *this; }
builder_perm& builder_perm::salary(int s) { p.salariu = s; return *this; }
//Data<T> instead? (as parameter) + template<typename T>
builder_perm& builder_perm::emp_date(Data ed) { p.data_angajare = ed; return *this; }
builder_perm& builder_perm::nr_children(int nc) { p.nr_minori_intretinere = nc; return *this; }
Permanent builder_perm::finish() { return p; }

builder_part& builder_part::name(std::string n) { p.nume = n; return *this; }
builder_part& builder_part::pname(std::string pn) { p.prenume = pn; return *this; }
builder_part& builder_part::salary(int s) { p.salariu = s; return *this; }
//Data<T> instead? (as parameter) + template<typename T>
builder_part& builder_part::emp_date(Data ed) { p.data_angajare = ed; return *this; }
builder_part& builder_part::ore_luc(int o) { p.nr_ore_zi = o; return *this; }
//Data<T> instead? (as parameter) + template<typename T>
builder_part& builder_part::fire_date(Data fd) { p.final_contract = fd; return *this; }
Part_Time builder_part::finish() { return p; }

//pentru toate clasele eventual? fiind folosit template ca membru;