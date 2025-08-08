--Daniel Desforges
--CS325 Fall 2020
--November 21 2020

create table Customer
(CustomerID integer,
Name varchar(15),
PhoneNumber integer,
Purchases varchar(20),
primary key(CustomerID));

create table Instruments
(InstrumentID integer,
InstrumentType varchar(15),
PurchaseID integer,
IsAntique BIT,
primary key(InstrumentID),
foreign key(PurchaseID, CustomerID));

create table ShopOperator
(OperatorID integer,
RecievedPayment decimal(10, 2),
OperatorName varchar(15),
primary key (OperatorID),
foreign key(RecievedPayment, InstrumentID));

create table StringInstruments
(InstrumentID integer,
StringType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key(StringType, InstrumentID));

StoredLocation varchar(40),
primary key(InstrumentID),
foreign key(StringType, InstrumentID));

create table Violins
(InstrumentID integer,
IsString varchar(15),
Cost decimal(10,2),
Strings varchar(40),
primary key(InstumentID),
forign key(IsString, InstrumentID));

create table Harps
(InstrumentID integer,
IsString varchar(15),
Cost decimal(10,2),
Strings varchar(40),
primary key(InstumentID),
forign key(IsString, InstrumentID));

create table Guitars
(InstrumentID integer,
IsString varchar(15),
Cost decimal(10,2),
Strings varchar(40),
primary key(InstumentID),
forign key(IsString, InstrumentID));

create table WindInstruments
(InstrumentID integer,
WindType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key(WindType, InstrumentID));

create table FrenchHorns
(InstrumentID integer,
IsWind varchar(15),
Cost decimal(10,2),
Size varchar(40),
primary key(InstumentID),
forign key(IsWind, InstrumentID));

create table Bugals
(InstrumentID integer,
IsWind varchar(15),
Cost decimal(10,2),
Size varchar(40),
primary key(InstumentID),
forign key(IsWind, InstrumentID));

create table Tubas
(InstrumentID integer,
IsWind varchar(15),
Cost decimal(10,2),
Size varchar(40),
primary key(InstumentID),
forign key(IsWind, InstrumentID));

create table PrecussionInstruments
(InstrumentID integer,
PrecussionType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key(PrecussionType, InstrumentID));

create table Snares
(InstrumentID integer,
IsPrecussion varchar(15),
Cost decimal(10,2),
Color varchar(40),
primary key(InstumentID),
forign key(IsPrecussion, InstrumentID));

create table BaseDrums
(InstrumentID integer,
IsPrecussion varchar(15),
Cost decimal(10,2),
Color varchar(40),
primary key(InstumentID),
forign key(IsPrecussion, InstrumentID));

create table Bongos
(InstrumentID integer,
IsPrecussion varchar(15),
Cost decimal(10,2),
Color varchar(40),
primary key(InstumentID),
forign key(IsPrecussion, InstrumentID));

