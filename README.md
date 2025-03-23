# CSE4110 Database System Projects 🚀

이 저장소는 **CSE4110 Database System** 수업에서 수행한 두 개의 프로젝트를 포함하고 있습니다.  
이 프로젝트는 **배달업체의 주문 및 배달 관리 시스템**을 설계하고 구현하는 과정을 다룹니다.  
E-R 모델링, 관계형 스키마 설계, 정규화, SQL 쿼리 작성 및 C/C++과 MySQL을 활용한 애플리케이션 구현을 포함합니다.  

---

## 📑 **Table of Contents**
1. [Project 1: E-R Design and Relational Schema](#project-1-e-r-design-and-relational-schema)
2. [Project 2: Normalization and Query Processing](#project-2-normalization-and-query-processing)

---

## 📌 **Project 1: E-R Design and Relational Schema**
### 📌 **Overview**
이 프로젝트의 목표는 **배달업체의 주문 및 배달 관리 시스템**을 위한 관계형 데이터베이스를 설계하는 것입니다.  
배달업체는 고객의 주문을 처리하고, 배달원에게 배정하며, 배달 상태를 추적합니다.  
이 프로젝트에서는 **E-R 모델링을 수행하고 관계형 스키마를 설계한 후, SQL 쿼리를 작성하여 데이터 조회 기능을 구현**합니다.  

### 📦 **Application Description**
배달업체 데이터베이스는 다음과 같은 주요 엔터티를 포함해야 합니다.  

- 📌 **고객 (Customers)**: 배달 앱을 통해 주문을 하는 사용자  
- 📌 **주문 (Orders)**: 고객이 요청한 배달 주문 (음식, 물건 등) 
- 📌 **판매자 (Orders)**: 고객이 주문한 물품을 판매매  
- 📌 **트럭**: 트럭을 통해 소포가 이동  
- 📌 **창고**: 소포가 이동중 머무는 장소  
- 📌 **결제 (Payments)**: 주문에 대한 결제 처리  
- 📌 **배달 상태 (Delivery Status)**: 주문이 배달되는 진행 상태 (주문 접수, 준비 중, 배달 중, 완료)  

📌 **배달 관련 데이터는 실제 배달 서비스(예: 배달의민족, 쿠팡이츠 등)의 주문 흐름을 참고하여 샘플 데이터를 생성합니다.**  

### 📜 **Requirements**
#### ✅ **E-R 모델**
- 배달 시스템의 개념적 설계를 위한 **E-R 다이어그램**을 작성  
- **주요 엔터티, 관계, 속성, 키 제약 조건 정의**  
- **중복 데이터를 최소화하고 관계성을 명확히 정의**  

#### ✅ **관계형 스키마**
- E-R 모델을 기반으로 **관계형 데이터베이스 스키마** 설계  
- **ERwin Data Modeler**를 사용하여 스키마를 정의하고 제약 조건 추가  
- 각 테이블에 **기본 키(Primary Key), 외래 키(Foreign Key), 속성 및 데이터 타입 명시**  

#### ✅ **SQL Queries**
- 다양한 데이터를 조회할 수 있도록 **SQL 쿼리 작성**  
- **예제 쿼리**
  - 특정 지역에서 주문된 배달 내역 조회  
  - 특정 기간 동안의 총 주문 수 및 총 수익 계산    

---

## 📌 **Project 2: Normalization and Query Processing**
### 📌 **Overview**
이 프로젝트에서는 **관계형 데이터베이스를 정규화(BCNF)하고, MySQL을 연동하는 C/C++ 애플리케이션을 개발**합니다.  
배달업체의 데이터베이스를 보다 효율적으로 관리하고, 애플리케이션을 통해 CRUD(Create, Read, Update, Delete) 연산을 수행합니다.  

### 🖥️ **System Setup**
#### ✅ **Software Stack**
- **C/C++ Application**: 데이터베이스와 상호작용하는 애플리케이션 개발  
- **MySQL ODBC Driver**: 애플리케이션과 MySQL을 연결  
- **MySQL Server**: 배달 관리 시스템 데이터베이스 운영  

#### ✅ **설치 및 실행 환경 (Windows)**
1. **MySQL Server 및 MySQL Workbench 설치**  
2. **MySQL ODBC 드라이버 설치** (C/C++ 애플리케이션과 DB 연동)  
3. **MySQL Workbench 또는 CLI를 사용하여 데이터베이스 생성**  

### 📜 **Requirements**
#### ✅ **BCNF 정규화**
- 기존 관계형 스키마를 **BCNF(Boyce-Codd Normal Form)**로 변환  
- **중복을 줄이고 무결성을 유지하면서 의존성을 최소화**  

#### ✅ **물리적 스키마 (Physical Schema)**
- 정규화된 테이블을 기반으로 **물리적 스키마 다이어그램 작성**  
- **데이터 타입, 제약 조건 및 NULL 허용 여부 명시**  

#### ✅ **SQL Queries**
- 다양한 CRUD 연산을 수행하는 SQL 쿼리 작성  
- **예제 쿼리**
  - 특정 고객의 최근 주문 조회  

#### ✅ **C/C++ 애플리케이션 개발**
- MySQL과 ODBC를 활용하여 **데이터베이스와 상호작용하는 프로그램 구현**  
- **기능**
  - CRUD 연산 수행 (고객, 배달원, 주문, 결제 등)  
  - SQL 쿼리를 실행하여 데이터 조회  
  - 사용자가 메뉴를 선택하고 입력값을 제공하여 결과 확인  
  - `"quit"` 입력 시 프로그램 종료  
