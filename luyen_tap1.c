#include <stdio.h>
#include <string.h>

typedef struct {
	int maSach;
	char tenSach[50];
	char tacGia[30];
	float giaTien;
	char theLoai[20];
} Sach;

void addInfo( Sach sach[], int *n );
void show( Sach sach[], int n);
void addItem( Sach sach[], int *n );
void updateItem( Sach sach[], int n);
void delItem( Sach sach[], int *n );
void sort( Sach sach[], int n );
void search( Sach sach[], int n );


int main(){
	Sach sach[100];
	int choice, check = -1, n = 0;
	do{
		printf("\n\n------------Menu------------");
		printf("\n1. Nhap so luong va thong tin sach ");
		printf("\n2. Hien thi thong tin sach ");
		printf("\n3. Them sach vao vi tri ");
		printf("\n4. Xoa sach theo ma sach ");
		printf("\n5. Cap nhat thong tin theo ma sach ");
		printf("\n6. Sap xep sach theo gia(tang/giam) ");
		printf("\n7. Tim kiem sach theo ten ");
		printf("\n8. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice );
		fflush(stdin);
		
		switch( choice){
			case 1:{
				check = 1;
				addInfo(sach, &n);
				break;
			}
			case 2:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					show(sach, n);
				}
				break;
			}
			case 3:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					addItem(sach, &n);
				}
				break;
			}
			case 4:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					delItem(sach, &n);
				}
				break;
			}
			case 5:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					updateItem(sach, n);
				}
				break;
			}
			case 6:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sort(sach, n);
				}
				break;
			}
			case 7:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					search(sach, n);
				}
				break;
			}
			case 8:{
				printf("\nBan chon thoat! ");
				break;
			}
			default:{
				printf("\nVui long chon dung menu(1-8)");
				break;
			}
		}
	}while( choice!=8);

	return 0;
}

void addInfo( Sach sach[], int *n ){
	printf("\nNhap so luong sach: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n ; i++){
		sach[i].maSach = i+1 ;
		printf("\nNhap thong tin sach thu %d: ", i+1);
		printf("\nNhap ten sach: ");
		fgets(sach[i].tenSach , 50, stdin);
		sach[i].tenSach[strlen(sach[i].tenSach) -1] = '\0' ;
		
		printf("Nhap tac gia: ");
		fgets(sach[i].tacGia , 30, stdin);
		sach[i].tacGia[strlen(sach[i].tacGia) -1] = '\0' ;
		
		printf("Nhap the loai: ");
		fgets(sach[i].theLoai , 30, stdin);
		sach[i].theLoai[strlen(sach[i].theLoai) -1] = '\0' ;
		
		printf("Nhap gia tien: ");
		scanf("%f", &sach[i].giaTien);
		fflush(stdin);
	}
}

void show( Sach sach[], int n){
	printf("\nDanh sach: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
		printf("\n Tac gia: %s", sach[i].tacGia);
		printf("\n The loai: %s", sach[i].theLoai);
		printf("\n Gia tien: %.2f", sach[i].giaTien);
	}
}

void addItem( Sach sach[], int *n ){
	int index;
	do{
		printf("\n Nhap vi tri muon them(1-%d): ", (*n)+1);
		scanf("%d", &index);
	}while(index<1 || index> (*n)+1);
	fflush(stdin);
	
	for ( int i = *n; i>= index ; i--){
		sach[i] = sach[i-1];
		sach[i].maSach  = sach[i-1].maSach + 1 ;
	}
	
	sach[index-1].maSach = index ;
	printf("\nNhap ten sach: ");
	fgets(sach[index-1].tenSach , 50, stdin);
	sach[index-1].tenSach[strlen(sach[index-1].tenSach) -1] = '\0' ;
	
	printf("Nhap tac gia: ");
	fgets(sach[index-1].tacGia , 30, stdin);
	sach[index-1].tacGia[strlen(sach[index-1].tacGia) -1] = '\0' ;
	
	printf("Nhap the loai: ");
	fgets(sach[index-1].theLoai , 30, stdin);
	sach[index-1].theLoai[strlen(sach[index-1].theLoai) -1] = '\0' ;
	
	printf("Nhap gia tien: ");
	scanf("%f", &sach[index-1].giaTien);
	fflush(stdin);
	
	(*n)++;	
	printf("\nDanh sach ket qua: ");
	for ( int i = 0; i< *n ; i++){
		printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
		printf("\n Tac gia: %s", sach[i].tacGia);
		printf("\n The loai: %s", sach[i].theLoai);
		printf("\n Gia tien: %.2f", sach[i].giaTien);
	}
}

void updateItem( Sach sach[], int n ){
	int index, input, check = -1;
	printf("\n Nhap ma sach muon sua: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< n; i++){
		if ( sach[i].maSach == input ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma sach can sua!");
	}else{
		printf("\nNhap ten sach: ");
		fgets(sach[index].tenSach , 50, stdin);
		sach[index].tenSach[strlen(sach[index].tenSach) -1] = '\0' ;
		
		printf("Nhap tac gia: ");
		fgets(sach[index].tacGia , 30, stdin);
		sach[index].tacGia[strlen(sach[index].tacGia) -1] = '\0' ;
		
		printf("Nhap the loai: ");
		fgets(sach[index].theLoai , 30, stdin);
		sach[index].theLoai[strlen(sach[index].theLoai) -1] = '\0' ;
		
		printf("Nhap gia tien: ");
		scanf("%f", &sach[index].giaTien);
		fflush(stdin);
			
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i<n ; i++){
			printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
			printf("\n Tac gia: %s", sach[i].tacGia);
			printf("\n The loai: %s", sach[i].theLoai);
			printf("\n Gia tien: %.2f", sach[i].giaTien);
		}
	}
}

void delItem( Sach sach[], int *n ){
	int index, input, check = -1;
	printf("\n Nhap ma sach muon xoa: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< *n; i++){
		if ( sach[i].maSach == input ){
			index = i;
			check = 1;
			break;
		} 
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma sach can sua!");
	}else {
		for ( int i = index ; i < *n ; i++){
			sach[i].maSach  = sach[i+1].maSach - 1 ;
			sach[i] = sach[i+1];
		}
		
		(*n)--;	
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i< *n ; i++){
			printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
			printf("\n Tac gia: %s", sach[i].tacGia);
			printf("\n The loai: %s", sach[i].theLoai);
			printf("\n Gia tien: %.2f", sach[i].giaTien);
		}
	}
}

void sort( Sach sach[], int n){
	char choice;
	do{
		printf("\na. Gia tang dan");
		printf("\nb. Gia giam dan");
		printf("\nLua chon cua ban: ");
		scanf("%c", &choice );
		fflush(stdin);
	}while( choice != 'a' && choice != 'b' );
	fflush(stdin);
	
	if ( choice == 'a' ){
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( sach[j].giaTien > sach[j+1].giaTien  ){
					Sach temp = sach[j];
	                sach[j] = sach[j+1];
	                sach[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( sach[j].giaTien < sach[j+1].giaTien  ){
					Sach temp = sach[j];
	                sach[j] = sach[j+1];
	                sach[j+1] = temp;
				}
			}
		}
	}
	
	printf("\nDanh sach: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
		printf("\n Tac gia: %s", sach[i].tacGia);
		printf("\n The loai: %s", sach[i].theLoai);
		printf("\n Gia tien: %.2f", sach[i].giaTien);
	}
}

void search( Sach sach[], int n){
	char input[50];
	int count = 0;
	
	fflush(stdin);
	printf("\nNhap ten sach can tim: ");
	
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strstr(sach[i].tenSach, input) != NULL ){
			count = 1;
			printf("\nKet qua tim kiem: ");
			printf("\n\n %d. %s", sach[i].maSach, sach[i].tenSach);
			printf("\n Tac gia: %s", sach[i].tacGia);
			printf("\n The loai: %s", sach[i].theLoai);
			printf("\n Gia tien: %.2f", sach[i].giaTien);
		}
	}

	if ( count == 0 ) printf("\n Khong tim thay sach!");
}



