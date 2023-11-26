#pragma once
#pragma once
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//в состав SNILS входят number - номер СНИЛСа, pol - пол человека
typedef struct SNILS
{
	long long int number;
	int pol;
};

//в состав ID входят seria - серия паспорта, number - номер паспорта
typedef struct ID
{
	int seria;
	int number;
};

//в состав Docs входят snils - СНИЛС, id - паспорт
typedef struct Docs
{
	SNILS snils;
	ID id;
};

//в состав PersData входят docs - документы, age - возраст человека, fio - ФИО
typedef struct PersData
{
	Docs docs;
	int age;
	char* fio;
};

//в состав Auto входят brand - марка авто, model - модель авто, typeTrans - тип трансмиссии авто, gosNumber - гос номер авто
typedef struct Auto
{
	char* brand;
	char* model;
	int typeTrans;
	char* gosNumber;
};

//в состав Instructor входят autO - авто, persdata - персональные данные, driveExp - стаж вождения
typedef struct Instructor
{
	Auto autO;
	PersData persdata;
	int driveExp;
};

//в состав Client входят persdata - персональные данные, compless - пройденные уроки, totalless - всего уроков
typedef struct Client
{
	PersData persdata;
	int compless;
	int totalless;
};

//в состав Lesson входят client - клиент, intstructor - инструктор, data - дата, time - время, paymentstatus - статус оплаты
typedef struct Lesson
{
	Client client;
	Instructor intstructor;
	char* data;
	char* time;
	int paymentstatus;
};

//основные функции

//функции по инициализация всех структур

SNILS* CreateSNILS(int number, int pol) {
	if (number > 0 && pol > 0 && pol < 3) {
		SNILS* snils = (SNILS*)calloc(1, sizeof(SNILS));
		snils->number = number;
		snils->pol = pol;
		return snils;
	}
	else {
		printf("1Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

ID* CreateID(int seria, int number) {
	if (number > 0 && seria > 0) {
		ID* id = (ID*)calloc(1, sizeof(ID));
		id->number = number;
		id->seria = seria;
		return id;
	}
	else {
		printf("2Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

Docs* CreateDocs(SNILS snils, ID id) {
	Docs* docs = (Docs*)calloc(1, sizeof(Docs));
	docs->snils = snils;
	docs->id = id;
	return docs;
}

PersData* CreatePersData(Docs docs, int age, char* fio) {
	if (age > 0 && strlen(fio) != 0) {
		PersData* persdata = (PersData*)calloc(1, sizeof(PersData));
		persdata->fio = (char*)calloc(40, sizeof(char));
		strcpy(persdata->fio, fio);
		persdata->docs = docs;
		persdata->age = age;
		return persdata;
	}
	else {
		printf("3Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

Auto* CreateAuto(char* brand, char* model, int typeTrans, char* gosNumber) {
	if (strlen(model) != 0 && strlen(brand) != 0 && strlen(gosNumber) != 0 && typeTrans > 0 && typeTrans < 3) {
		Auto* autO = (Auto*)calloc(1, sizeof(Auto));
		autO->brand = (char*)calloc(40, sizeof(char));
		autO->model = (char*)calloc(40, sizeof(char));
		autO->gosNumber = (char*)calloc(40, sizeof(char));
		strcpy(autO->brand, brand);
		strcpy(autO->model, model);
		strcpy(autO->gosNumber, gosNumber);
		autO->typeTrans = typeTrans;
		return autO;
	}
	else {
		printf("4Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

Instructor* CreateInstructor(Auto autO, PersData persdata, int driveExp) {
	if (driveExp > 0) {
		Instructor* instructor = (Instructor*)calloc(1, sizeof(Instructor));
		instructor->autO = autO;
		instructor->persdata = persdata;
		instructor->driveExp = driveExp;
		return instructor;
	}
	else {
		printf("5Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

Client* CreateClient(PersData persdata, int compless, int totalless) {
	if (totalless > 0) {
		Client* client = (Client*)calloc(1, sizeof(Client));
		client->persdata = persdata;
		client->compless = compless;
		client->totalless = totalless;
		return client;
	}
	else {
		printf("6Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

Lesson* CreateLesson(Client client, Instructor intstructor, char* data, char* time, int paymentstatus) {
	if (strlen(data) != 0 && strlen(time) != 0 && paymentstatus > 0 && paymentstatus < 3) {
		Lesson* lesson = (Lesson*)calloc(1, sizeof(Lesson));
		lesson->client = client;
		lesson->intstructor = intstructor;
		lesson->data = (char*)calloc(40, sizeof(char));
		lesson->time = (char*)calloc(40, sizeof(char));
		strcpy(lesson->data, data);
		strcpy(lesson->time, time);
		lesson->paymentstatus = paymentstatus;
		return lesson;
	}
	else {
		printf("7Неправильный ввод данных данных!");
		exit(EXIT_SUCCESS);
	}
}

//функции по вводу структур

SNILS* InputSNILS() {
	printf("\tВвод СНИЛСа\n");

	int number;
	long long int pol;

	printf("Введите номер СНИЛа: ");
	scanf("%d", &number);
	printf("Введите пол (1-мужской, 2- женский): ");
	scanf("%d", &pol);
	while (getchar() != '\n');
	return CreateSNILS(number, pol);
}

ID* InputID() {
	printf("\tВвод паспорта\n");

	int seria;
	int number;

	printf("Введите серию: ");
	scanf("%d", &seria);
	printf("Введите номер: ");
	scanf("%d", &number);
	while (getchar() != '\n');
	return CreateID(seria, number);
}

Docs* InputDocs() {
	printf("\tВвод документов\n");
	return CreateDocs(*InputSNILS(), *InputID());
}

PersData* InputPersData() {
	printf("\tВвод персональных данных\n");

	int age;
	char* fio = (char*)calloc(40, sizeof(char));

	printf("Введите возраст: ");
	scanf("%d", &age);
	printf("Введите ФИО: ");
	while (getchar() != '\n');
	gets_s(fio, 40);
	return CreatePersData(*InputDocs(), age, fio);
}

Auto* InputAuto() {
	printf("\tВвод параметров авто\n");

	char* brand = (char*)calloc(40, sizeof(char));
	char* model = (char*)calloc(40, sizeof(char));
	int typeTrans;
	char* gosNumber = (char*)calloc(40, sizeof(char));

	printf("Введите марку: ");
	gets_s(brand, 40);
	printf("Введите модель: ");
	gets_s(model, 40);
	printf("Введите тип трансмиссии(1- механика,2- автомат): ");
	scanf("%d", &typeTrans);
	printf("Введите гос номер: ");
	while (getchar() != '\n');
	gets_s(gosNumber, 40);
	return CreateAuto(brand, model, typeTrans, gosNumber);
}

Instructor* InputInstructor() {
	printf("\tВвод данных иструктора\n");


	int driveExp;

	printf("Введите стаж вождения: ");
	scanf("%d", &driveExp);
	while (getchar() != '\n');
	return CreateInstructor(*InputAuto(), *InputPersData(), driveExp);
}

Client* InputClient() {
	printf("\tВвод данных клиента\n");


	int compless;
	int totalless;

	printf("Введите кол-во пройденых уроков: ");
	scanf("%d", &compless);
	printf("Введите кол-во всех уроков: ");
	scanf("%d", &totalless);
	while (getchar() != '\n');
	return CreateClient(*InputPersData(), compless, totalless);
}

Lesson* InputLesson() {
	printf("\tВвод данных урока\n");

	char* data = (char*)calloc(40, sizeof(char));
	char* time = (char*)calloc(40, sizeof(char));
	int paymentstatus;

	printf("Введите дату: ");
	gets_s(data, 40);
	printf("Введите время: ");
	gets_s(time, 40);
	printf("Введите статус оплаты(1-оплачено, 2-неоплачено): ");
	scanf("%d", &paymentstatus);
	while (getchar() != '\n');
	return CreateLesson(*InputClient(), *InputInstructor(), data, time, paymentstatus);
}

void PrintInstructor(Instructor instructor) {
	printf("\tИфнормация об инструкторе\n");
	printf("ФИО - %s, Возраст - %d\n", instructor.persdata.fio, instructor.persdata.age);
	printf("Документы: Паспорт - %d %d, СНИЛС - %d\n", instructor.persdata.docs.id.seria, instructor.persdata.docs.id.number, instructor.persdata.docs.snils.number);
	printf("Машина: Марка - %s, Модель - %s, Гос. номер - %s, тип трансмиссии(1-механика, 2-автомат) - %d\n", instructor.autO.brand, instructor.autO.model, instructor.autO.gosNumber, instructor.autO.typeTrans);
}

void PrintLesson(Lesson lesson) {
	printf("\tИнформация об уроке\n");
	printf("Дата - %s, Время- %s, Статус оплаты(1-оплачено, 2-неоплачено) - %d\n", lesson.data, lesson.time, lesson.paymentstatus);
}

void PrintClient(Client client) {
	printf("\tИфнормация о клиенте\n");
	printf("ФИО - %s, Возраст - %d\n", client.persdata.fio, client.persdata.age);
	printf("Документы: Паспорт - %d %d, СНИЛС - %d\n", client.persdata.docs.id.seria, client.persdata.docs.id.number, client.persdata.docs.snils.number);
}

//изменение статуса оплаты урока
void ChangeStatus(Lesson* lesson, int newStatus) {
	if (newStatus > 0 && newStatus < 3) {
		lesson->paymentstatus = newStatus;
		printf("Статус оплаты успешно изменено!\n");
	}
	else {
		printf("Неправильный формат данных!");
		exit(EXIT_SUCCESS);
	}
}
//освобождение памяти для объектов внутри Lesson
void FreeLessonMemory(Lesson* lesson) {
	free(lesson->data);
	free(lesson->time);
	free(lesson->intstructor.persdata.fio);
	free(lesson->intstructor.autO.brand);
	free(lesson->intstructor.autO.gosNumber);
	free(lesson->intstructor.autO.model);
	free(lesson->client.persdata.fio);
}