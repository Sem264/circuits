SELECT firstName, lastName
FROM Person.Person
WHERE lastName LIKE '%b%';

SELECT firstName, lastName
FROM Person.Person
WHERE lastName LIKE '%b';

SELECT firstName, lastName
FROM Person.Person
WHERE (lastName LIKE 'Ac%') OR (lastName LIKE 'Za%');

SELECT COUNT(*) AS 'Number of last names Ca…l'
FROM Person.Person
WHERE (lastName LIKE 'Ca%') AND (lastName LIKE '%l');

SELECT firstName, lastName
FROM Person.Person
WHERE lastName LIKE '%d%d%';

SELECT E.BusinessEntityID, P.FirstName + ', ' + P.LastName AS Name, E.JobTitle, E.Gender
FROM HumanResources.Employee AS E, Person.Person AS P
WHERE E.BusinessEntityID = P.BusinessEntityID;

SELECT COALESCE(AddressLine1 +' '+ AddressLine2, AddressLine1)  AS Address, City
FROM Person.Address

