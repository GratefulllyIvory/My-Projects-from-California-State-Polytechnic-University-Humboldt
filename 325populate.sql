--Daniel Desforges
--CS325 Fall 2020
--December 5 2020
PROMPT -- Remember to Run 325droptable.sql after first load
create table CustomerList
(CustomerID integer,
Name varchar(15),
PhoneNumber integer,
Purchases varchar(20),
primary key(CustomerID));

insert into CustomerList
values
( 1, 'Michael', 9518274627, 'Steel String Guitar');
insert into CustomerList
values
( 2 , 'Jane', 9091284253, 'Nylon String Violin');
insert into CustomerList
values
( 3 , 'Joe', 9719239032, 'Standard String Harp');
insert into CustomerList
values
( 4 , 'Alice', 7428912322, 'XL FrenchHorn');
insert into CustomerList
values
( 5 , 'Bob', 8237286456, 'Red Bongos');
insert into CustomerList
values
( 6 , 'Jameson', 9285391092, 'Green Snares');
insert into CustomerList
values
( 7 , 'Jack', 9710293218, 'Alloy String Guitar');
insert into CustomerList
values
( 8 , 'Brian', 9173245832, 'Blue BaseDrum');
insert into CustomerList
values
( 9 , 'Thomas', 8721245760, 'Small Tuba');
insert into CustomerList
values
( 10 , 'Vik', 3256098341, 'Standard Bugal');


create table Instrumentz
(InstrumentID integer,
PurchaseID integer,
InstrumentType varchar(15),
IsAntique varchar(10),
primary key(InstrumentID),
foreign key (PurchaseID) references CustomerList(CustomerID));
PROMPT --Sample Set of Instruments
insert into Instrumentz
values
( 11 , 1 , 'String' , 'Yes');
insert into Instrumentz
values
( 12, 2 , 'String' , 'No');
insert into Instrumentz
values
( 13, 3 , 'String' , 'Yes');
insert into Instrumentz
values
( 14, 4 , 'String' , 'Yes');
insert into Instrumentz
values
( 15, 5 , 'String' , 'No');
insert into Instrumentz
values
( 16, 6 , 'String' , 'Yes');
insert into Instrumentz
values
( 17, 7 , 'String' , 'Yes');
insert into Instrumentz
values
( 18, 8 , 'String' , 'Yes');
insert into Instrumentz
values
( 19, 9 , 'String' , 'Yes');
insert into Instrumentz
values
( 20, 10,'String' , 'No');

create table ShopOperators
(OperatorID integer,
RecievedPaymentID integer,
PaymentAmount decimal(10,2),
OperatorName varchar(15),
primary key (OperatorID),
foreign key (RecievedPaymentID) references Instrumentz(InstrumentID));
insert into ShopOperators
values
( 21, 11, 3240120.34 , 'Dante');
insert into ShopOperators
values
( 22, 12 , 10000.10 , 'Virgil');
insert into ShopOperators
values
( 23, 13, 102030.14, 'Dante');
insert into ShopOperators
values
( 24, 14, 240142.34, 'Dante');
insert into ShopOperators
values
( 25, 15, 368.43, 'Virgil');
insert into ShopOperators
values
( 26, 16, 11142.45, 'Dante');
insert into ShopOperators
values
( 27, 17, 152432.53, 'Dante');
insert into ShopOperators
values
( 28, 18, 2221115.22, 'Virgil');
insert into ShopOperators
values
( 29, 19, 2515255.11, 'Dante');

create table StringInstruments
(InstrumentID integer,
StringType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references Instrumentz(InstrumentID));
insert into StringInstruments
values
(11, 'Steel', 'BackRoom');
insert into StringInstruments
values
(12, 'Nickle' , 'Attic');
insert into StringInstruments
values
(13, 'Nylon', 'Front Window');
insert into StringInstruments
values
(14, 'Bronze', 'BackRoom');
insert into StringInstruments
values
(15,'Steel', 'Attic');
insert into StringInstruments
values
(16, 'Steel', 'FrontRoom');
insert into StringInstruments
values
(17, 'Nickle' , 'BackRoom');
insert into StringInstruments
values
(18, 'Nylon', 'Backroom');
insert into StringInstruments
values
(19, 'Brass', 'MiddleCase');
insert into StringInstruments
values
(20, 'Catgut', 'UpperShelf');

create table Violins
(InstrumentID integer,
IsString varchar(15),
Strings varchar(40),
primary key(InstrumentID),
foreign key(InstrumentID) references StringInstruments(InstrumentID));
PROMPT -- SubSet of StringInstruments
insert into Violins
values
(11, 'Yes', 'Steel');
insert into Violins
values
(13, 'Yes','Nylon');
insert into Violins
values
(20, 'Yes', 'Catgut');

create table Harp
(InstrumentID integer,
IsString varchar(15),
Strings varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references StringInstruments(InstrumentID));
PROMPT -- SubSet of StringInstruments
insert into Harp
values
(12, 'Yes', 'Nickle');
insert into Harp
values
(14, 'Yes', 'Bronze');
insert into Harp
values
(15, 'Yes', 'Steel');

create table Guitars
(InstrumentID integer,
IsString varchar(15),
Strings varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references StringInstruments(InstrumentID));
PROMPT -- SubSet of StringInstruments
insert into Guitars
values
(16, 'Yes', 'Steel');
insert into Guitars
values
(17, 'Yes', 'Nickle');
insert into Guitars
values
(18, 'Yes', 'Nylon');
insert into Guitars
values
(20, 'Yes', 'Catgut');

create table WindInstruments
(InstrumentID integer,
WindType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references Instrumentz(InstrumentID));
insert into WindInstruments
values
(11, 'Direct', 'BackRoom');
insert into WindInstruments
values
(12, 'Standard',  'Attic');
insert into WindInstruments
values
(13, 'Indirect', 'Front Window');
insert into WindInstruments
values
(14, 'Direct', 'BackRoom');
insert into WindInstruments
values
(15,'Direct', 'Attic');
insert into WindInstruments
values
(16, 'Standard', 'FrontRoom');
insert into WindInstruments
values
(17, 'Direct' , 'BackRoom');
insert into WindInstruments
values
(18, 'Indirect', 'Backroom');
insert into WindInstruments
values
(19, 'Standard', 'MiddleCase');
insert into WindInstruments
values
(20, 'Indirect', 'UpperShelf');

create table FrenchHorn
(InstrumentID integer,
IsWind varchar(15),
WindType varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references WindInstruments(InstrumentID));
insert into FrenchHorn
values
(12,'Yes', 'Standard');
insert into FrenchHorn
values
(16, 'Yes', 'Standard');
insert into FrenchHorn
values
(19, 'Yes', 'Standard');

create table Bugals
(InstrumentID integer,
IsWind varchar(15),
WindType varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references WindInstruments(InstrumentID));
insert into Bugals
values
(11, 'Yes', 'Direct');
insert into Bugals
values
(14, 'Yes', 'Direct');
insert into Bugals
values
(15, 'Yes', 'Direct');
insert into Bugals
values
(17, 'Yes', 'Direct');

create table Tubas
(InstrumentID integer,
IsWind varchar(15),
WindType varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID)references WindInstruments(InstrumentID));
insert into Tubas
values
(18, 'Yes', 'Indirect');
insert into Tubas
values
(20, 'Yes', 'Indirect');
insert into Tubas
values
(13, 'Yes', 'Indirect');

create table PrecussionInstruments
(InstrumentID integer,
PrecussionType varchar(20),
StoredLocation varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references Instrumentz(InstrumentID));
insert into PrecussionInstruments
values
(11, 'Direct', 'BackRoom');
insert into PrecussionInstruments
values
(12, 'Standard',  'Attic');
insert into PrecussionInstruments
values
(13, 'Indirect', 'Front Window');
insert into PrecussionInstruments
values
(14, 'Direct', 'BackRoom');
insert into PrecussionInstruments
values
(15,'Direct', 'Attic');
insert into PrecussionInstruments
values
(16, 'Standard', 'FrontRoom');
insert into PrecussionInstruments
values
(17, 'Direct' , 'BackRoom');
insert into PrecussionInstruments
values
(18, 'Indirect', 'Backroom');
insert into PrecussionInstruments
values
(19, 'Standard', 'MiddleCase');
insert into PrecussionInstruments
values
(20, 'Indirect', 'UpperShelf');

create table Snares
(InstrumentID integer,
IsPrecussion varchar(15),
Color varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references PrecussionInstruments(InstrumentID));
insert into Snares
values
(11, 'Direct', 'Blue');
insert into Snares
values
(14, 'Direct', 'Black');
insert into Snares
values
(15,'Direct', 'Red');
insert into Snares
values
(17, 'Direct' , 'Green');

create table BaseDrums
(InstrumentID integer,
IsPrecussion varchar(15),
Color varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) references PrecussionInstruments(InstrumentID));
insert into BaseDrums
values
(18, 'Indirect', 'Purple');
insert into BaseDrums
values
(20, 'Indirect', 'Red');
insert into BaseDrums
values
(13, 'Indirect', 'Yellow');

create table Bongos
(InstrumentID integer,
IsPrecussion varchar(15),
Color varchar(40),
primary key(InstrumentID),
foreign key (InstrumentID) REFERENCES PrecussionInstruments(InstrumentID));
insert into Bongos
values
(19, 'Standard', 'Red');
insert into Bongos
values
(12, 'Standard',  'Blue');
insert into Bongos
values
(16, 'Standard', 'Green');

