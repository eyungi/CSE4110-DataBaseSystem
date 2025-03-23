#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"

#pragma comment(lib, "libmysql.lib")
#define MAXSIZE 2048

const char* host = "localhost";
const char* user = "root";
const char* pw = "dldbsrl0221!";
const char* db = "project2";

int main(void) {

	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	FILE* fp_i = fopen("20192136.txt", "r");
	if (fp_i == NULL)
	{
		printf("input file error\n");
	}

	char query[MAXSIZE];
	char* buffer = NULL;
	long long int size;
	int state = 0, type, subtype, flag = 0, year, month;
	fseek(fp_i, 0, SEEK_END);
	size = ftell(fp_i);
	buffer = (char*)malloc((int)size + 1);
	memset(buffer, 0, (int)size + 1);
	fseek(fp_i, 0, SEEK_SET);
	fread(buffer, (int)size, 1, fp_i);

	if (mysql_init(&conn) == NULL)
		printf("mysql_init() error!");

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL)
	{
		printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 1;
	}

	else
	{
		printf("Connection Succeed\n");

		if (mysql_select_db(&conn, db))
		{
			printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
			return 1;
		}

		//�� ������ Ȯ��
		const char* init = strtok(buffer, ";");
		while (1) {
			if (strstr(init, "drop table")) break;
			state = 0;
			state = mysql_query(connection, init);
			if (state != 0) printf("failure %s\n", init);
			init = strtok(NULL, ";");
		}
		while (1) {
			printf("------- SELECT QUERY TYPES -------\n\n");
			printf("\t1. TYPE I\n");
			printf("\t2. TYPE II\n");
			printf("\t3. TYPE III\n");
			printf("\t4. TYPE IV\n");
			printf("\t5. TYPE V\n");
			printf("\t0. QUIT\n");
			printf("----------------------------------\n");
			printf("Select Number: ");
			scanf("%d", &type);
			getchar();

			switch (type) {

			case 1:
				printf("\n\n---- TYPE 1 ----\n\n");
				printf("Truck 1721 is destroyed in a crash\n");
				printf("----------------------------------\n");
				printf("---- Subtypes in Type I----\n");
				printf("	1. TYPE I-1\n");
				printf("	2. TYPE I-2\n");
				printf("	3. TYPE I-3\n");
				printf("Select Number(If you want to go main menu, enter any integer except 1, 2): ");
				scanf("%d", &subtype);
				getchar();
				if (subtype == 1) {
					printf("\n\n---- TYPE I-1 ----\n\n");
					printf("The Truck number 1721 is crashed\n");
					printf("Find all customers who had a package on the truck at thetime of the crash.\n");
					sprintf(query, "select ShipperID from Shipment S natural join locationhistory L where LocationID = \"1721\" and S.DeliveryTimestamp is null;");
					state = 0;
					state = mysql_query(connection, query);
					if (state == 0)
					{
						sql_result = mysql_store_result(connection);
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("CustomerID : %s\n", sql_row[0]);
						}
						printf("\n");
						printf("----------------------------------\n");
						mysql_free_result(sql_result);
					}
					else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
				}
				else if (subtype == 2) {
					printf("\n\n---- TYPE I-2 ----\n\n");
					printf("The Truck number 1721 is crashed\n");
					printf("Find all recipients who had a package on that truck at the time of the crash.");
					sprintf(query, "select CustomerID from Shipment S natural join locationhistory L where LocationID = \"1721\" and S.DeliveryTimestamp is null;");
					state = 0;
					state = mysql_query(connection, query);
					if (state == 0)
					{
						sql_result = mysql_store_result(connection);
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("RecipientsID : %s\n", sql_row[0]);
						}
						printf("\n");
						printf("----------------------------------\n");
						mysql_free_result(sql_result);
					}
					else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				}
				else if (subtype == 3) {
					printf("\n\n---- TYPE I-3 ----\n\n");
					printf("The Truck number 1721 is crashed\n");
					printf("Find the last successful delivery by that truck prior to the crash.");
					sprintf(query, "select C.CustomerID,C.name,C.address  from Customer C natural join Shipment S where S.DeliveryTimestamp = (select max(DeliveryTimestamp) from Shipment S natural join locationhistory L where LocationID = \"1721\");");
					state = 0;
					state = mysql_query(connection, query);
					if (state == 0)
					{
						sql_result = mysql_store_result(connection);
						while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
						{
							printf("RecipientsID : %s, Recipients name %s, Recipients address : %s\n", sql_row[0], sql_row[1], sql_row[2]);
						}
						printf("\n");
						printf("----------------------------------\n");
						mysql_free_result(sql_result);
					}
					else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				}
				break;

			case 2:
				printf("\n\n---- TYPE II ----\n\n");
				printf("Find the customer who has shipped the most packages in the past year.\n");
				printf("Which year?");
				scanf("%d", &year);
				sprintf(query, "with VIP(ShipperID, cnt) as (select ShipperID, count(PackageID) as cnt from ((Package natural join Service) natural join Tariff) natural join Shipment S where year(S.DeliveryTimestamp) = \"%d\" group by ShipperID) select ShipperID, cnt from VIP V where V.cnt >= all(select cnt from VIP);", year);
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s, count : %s\n", sql_row[0], sql_row[1]);
					}
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				break;

			case 3:
				printf("\n\n---- TYPE III ----\n\n");
				printf("Find the customer who has spent the most money on shipping in the past year.\n");
				printf("Which year?");
				scanf("%d", &year);
				sprintf(query, "with VIP(ShipperID, total) as (select ShipperID, sum(Fee) as total from ((Package natural join Service) natural join Tariff) natural join Shipment S where year(S.DeliveryTimestamp) = \"%d\" group by ShipperID) select ShipperID, total from VIP V where V.total >= all(select total from VIP);", year);
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s, Total : %s\n", sql_row[0], sql_row[1]);
					}
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				break;

			case 4:
				printf("\n\n---- TYPE IV ----\n\n");
				printf("Find the packages that were not delivered within the promised time.\n");
				sprintf(query, "select ShipmentID ,PackageID from Shipment natural join package where ((PromisedDeliveryTime = \"overnight\" and (day(PickupTimestamp) + 1 < day(DeliveryTimestamp))) or (PromisedDeliveryTime = \"second day\" and (day(PickupTimestamp) + 2 < day(DeliveryTimestamp))) or (PromisedDeliveryTime = \"larger\" and (day(PickupTimestamp) + 3 < day(DeliveryTimestamp))));");
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s, PackageID : %s\n", sql_row[0], sql_row[1]);
					}
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				break;

			case 5:
				printf("\n\n---- TYPE 5 ----\n\n");
				printf("Generate the bill for each customer for the past month. Consider creating several types of bills.\n");
				printf("Which year month?");
				scanf("%d %d", &year, &month);
				// simple bill
				printf("\n\n-------Simple Bill-------\n\n");
				sprintf(query, "select ShipperID, A.address, sum(Fee) from (((Package natural join Service) natural join Tariff) natural join Shipment S) natural join Shipper A where year(S.DeliveryTimestamp) = \"%d\" and month(S.DeliveryTimestamp) = \"%d\" group by ShipperID, A.address;", year, month);
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					sql_row = mysql_fetch_row(sql_result);
					printf("product_id: %s", sql_row[0]);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s , Customer address : %s, Total Fee : %s\n", sql_row[0], sql_row[1], sql_row[2]);
					}
					printf("\n");
					printf("----------------------------------\n");
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				// listing bill
				printf("\n\n-------Listing Bill-------\n\n");
				sprintf(query, "select ShipperID, A.address, servicetype, sum(Fee) from (((Package natural join Service) natural join Tariff) natural join Shipment S) natural join Shipper A where year(S.DeliveryTimestamp) = \"%d\" and month(S.DeliveryTimestamp) = \"%d\" group by ShipperID, servicetype, A.address;", year, month);
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					sql_row = mysql_fetch_row(sql_result);
					printf("product_id: %s", sql_row[0]);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s , Customer address : %s, ServiceType : %s, Total Fee : %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
					}
					printf("\n");
					printf("----------------------------------\n");
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));

				// itemizing bill
				printf("\n\n-------Itemizing Bill-------\n\n");
				sprintf(query, "select ShipperID, ShipmentID, A.address, Fee from (((Package natural join Service) natural join Tariff) natural join Shipment S) natural join Shipper A where year(S.DeliveryTimestamp) = \"%d\" and month(S.DeliveryTimestamp) = \"%d\";", year, month);
				state = 0;
				state = mysql_query(connection, query);
				if (state == 0)
				{
					sql_result = mysql_store_result(connection);
					sql_row = mysql_fetch_row(sql_result);
					printf("product_id: %s", sql_row[0]);
					while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
					{
						printf("CustomerID : %s , ShipmentID : %s, Customer address : %s, Fee : %s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
					}
					printf("\n");
					printf("----------------------------------\n");
					mysql_free_result(sql_result);
				}
				else printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
				break;
			case 0:
				flag = 1;
				break;
			default:
				printf("Enter the right option(0~7).\n");
				break;
			}
			if (flag == 1) break;
		}

		//init = strtok(NULL, ";");

		while (init != NULL) {
			state = 0;
			state = mysql_query(connection, init);
			if (state != 0) printf("failure %s\n", init);
			init = strtok(NULL, ";");
		}

		mysql_close(connection);
	}

	return 0;
}



