
CREATE TABLE Author(
		id INT NOT NULL IDENTITY(1,1)
		CONSTRAINT pk_Author PRIMARY KEY,
		firstName VARCHAR(255) not null,
		lastName VARCHAR(255) not null
);

CREATE TABLE Publisher(
		id int not null IDENTITY(1,1)
		CONSTRAINT pk_Publisher PRIMARY KEY,
		name VARCHAR(255) not null,
		CONSTRAINT uq_Publisher UNIQUE(name)
);

DROP TABLE Publisher;

CREATE TABLE Formats(
		id INT not null IDENTITY(1,1)
		CONSTRAINT pk_Formats PRIMARY KEY,
		name VARCHAR(255) not null,
		CONSTRAINT uq_Formats UNIQUE(name)
);

CREATE TABLE Author_Writes(
		id INT NOT NULL IDENTITY(1,1)
		CONSTRAINT pk_AW PRIMARY KEY,
		authorId INT NOT NULL,
		bookISBN CHAR(13) NOT NULL
);

CREATE TABLE Book_Belongs(
		id INT NOT NULL IDENTITY(1,1)
		CONSTRAINT pk_BB PRIMARY KEY,
		formatId INT NOT NULL,
		bookISBN CHAR(13) NOT NULL
);

CREATE TABLE Book(
		isbn CHAR(13) NOT NULL
		CONSTRAINT pk_BookB PRIMARY KEY,
		rating DECIMAL(2,1),
		rated INT,
		published DATE NOT NULL,
		pages INT NOT NULL,
		title VARCHAR(255) NOT NULL,
		publisherId int NOT NULL
		CONSTRAINT fk_BookB FOREIGN KEY REFERENCES Publisher(id)
);

DROP TABLE BOOK;

INSERT INTO Publisher VALUES('Brush Education');

INSERT INTO Book VALUES('9781550596779', 4.6, 1, '2016-05-10', 56, 'A Short Introduction to Databases', 1);
INSERT INTO Book VALUES('1089930596779', 3.8, 891, '2010-10-11', 356, 'The Complete Canadian Book Editor', 1);

INSERT INTO Author VALUES('Gary B.', 'Shelly'),
	('Joy L.', 'Starks');

SELECT * FROM Author;
SELECT * FROM Book;
SELECT * FROM Publisher;


INSERT INTO Author_Writes VALUES(2,'1089930596779'),
	(3,'1089930596779'),
	(1,'9781550596779');

SELECT * FROM Author_Writes;

INSERT INTO Book_Belongs VALUES(1,'1089930596779'),
	(3,'1089930596779'),
	(4,'1089930596779');

SELECT * FROM Book_Belongs;