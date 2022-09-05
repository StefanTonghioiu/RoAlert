use master
if DB_ID('Ranubis') is not null
drop database Ranubis;
CREATE DATABASE Ranubis -- creazã baza de date
ON PRIMARY
(
Name = Ranubis,
FileName = 'D:\sql\Ranubis.mdf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 100MB
),
(
Name = Ranubis2,
FileName = 'D:\sql\Ranubis2.ndf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 100MB
),
(
Name = Ranubis3,
FileName = 'D:\sql\Ranubis3.ndf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 100MB
)
LOG ON
(
Name = RanubisLOG1,
FileName = 'D:\sql\RanubisLOG1.ldf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 100MB
),
(
Name = RanubisLOG2,
FileName = 'D:\sql\RanubisLOG2.ldf',
size = 10MB, -- KB, Mb, GB, TB
maxsize = unlimited,
filegrowth = 100MB
)

go
use Ranubis
IF NOT EXISTS (SELECT * FROM sysobjects WHERE name='DateConectare' AND xtype='U')
CREATE TABLE DateConectare
(
	IDUser int not null IDENTITY(1000,1) PRIMARY KEY,
	username varchar(20),
	parola varchar(257),
)
INSERT INTO DateConectare(username,parola)
VALUES
('faraonu', 'parola')