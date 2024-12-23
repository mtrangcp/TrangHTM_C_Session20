#include <stdio.h>
#include <string.h>

typedef struct {
	int maSP;
	char tenSP[50];
	float giaNhap;
	float giaBan;
	int soLuong;
} SanPham;

void addProd( SanPham sanPham[], int *n );
void show( SanPham sanPham[], int n);
void addItem( SanPham sanPham[], int *n, float *rev);
void updateItem( SanPham sanPham[], int n);
void sort( SanPham sanPham[], int n );
void search( SanPham sanPham[], int n );
void sell( SanPham sanPham[], int n, float *rev );
void revenue( float rev );

int main(){
	SanPham sanPham[100];
	int choice, check = -1, n = 0;
	float rev = 0;
	
	do{
		printf("\n\n------------Menu------------");
		printf("\n1. Nhap so luong va thong tin san pham ");
		printf("\n2. Hien thi danh sach san pham ");
		printf("\n3. Nhap san pham ");
		printf("\n4. Cap nhat thong tin san pham ");
		printf("\n5. Sap xep san pham theo gia(tang/giam) ");
		printf("\n6. Tim kiem san pham theo ten");
		printf("\n7. Ban san pham( co the nhap so luong can ban) ");
		printf("\n8. Doanh thu hien tai ");
		printf("\n9. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice );
		fflush(stdin);
		
		switch( choice){
			case 1:{
				check = 1;
				addProd( sanPham, &n );
				break;
			}
			case 2:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					show( sanPham, n);
				}
				break;
			}
			case 3:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					addItem(sanPham, &n, &rev);
				}
				break;
			}
			case 4:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					updateItem(sanPham, n);
				}
				break;
			}
			case 5:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sort(sanPham, n);
				}
				break;
			}
			case 6:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					search(sanPham, n);
				}
				break;
			}
			case 7:{
				if ( check == -1 ){
					printf("\nMang rong, vui long su dung chuc nang 1! ");
				}else{
					sell(sanPham, n, &rev);
				}
				break;
			}
			case 8:{
				revenue( rev);
				break;
			}
			case 9:{
				printf("\nBan chon thoat! ");
				break;
			}
			default:{
				printf("\nVui long chon dung menu(1-9)");
				break;
			}
		}
	}while( choice!=9);

	return 0;
}

void addProd( SanPham sanPham[], int *n ){
	printf("\nNhap so luong san pham: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n ; i++){
		sanPham[i].maSP = i+1 ;
		printf("\nNhap thong tin san pham thu %d: ", i+1);
		fflush(stdin);
		printf("\nNhap ten san pham: ");
		fgets(sanPham[i].tenSP , 50, stdin);
		sanPham[i].tenSP[strlen(sanPham[i].tenSP) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &sanPham[i].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sanPham[i].giaBan);
		printf("So luong: ");
		scanf("%d", &sanPham[i].soLuong);
	}
}

void show( SanPham sanPham[], int n){
	printf("\nDanh sach san pham: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
		printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
		printf("\n Gia ban: %.2f", sanPham[i].giaBan);
		printf("\n So luong: %d", sanPham[i].soLuong);
	}
}

void addItem( SanPham sanPham[], int *n, float *rev ){
	char input[50];
	int check = 0;
	
	printf("\nNhap thong tin san pham can them" );
	printf("\nNhap ten san pham: ");
	fgets(input, 50, stdin);
	input[strlen(input) -1] = '\0' ;
	
	for ( int i =0; i< *n; i++){
		if (  strcmp(sanPham[i].tenSP, input) == 0 ){
			check = 1;
			sanPham[i].soLuong += 1;
			*rev -= sanPham[i].giaNhap  ;
			break;
		}
	}
	
	if ( check == 0 ){
		strcpy( sanPham[*n].tenSP, input );
		
		sanPham[*n].maSP = (*n)+1;
		printf("Gia nhap: ");
		scanf("%f", &sanPham[*n].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sanPham[*n].giaBan);
		printf("So luong: ");
		scanf("%d", &sanPham[*n].soLuong);
		
		*rev -= sanPham[*n].giaNhap ;
		(*n)++ ;
	}
	
	printf("\nKet qua them san pham: ");
	for ( int i = 0; i< *n ; i++){
		printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
		printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
		printf("\n Gia ban: %.2f", sanPham[i].giaBan);
		printf("\n So luong: %d", sanPham[i].soLuong);
	}
}

void updateItem( SanPham sanPham[], int n){
	int index, input, check = -1;
	printf("\n Nhap ma san pham muon sua: ");
	scanf("%d", &input);
	fflush(stdin);
	
	for ( int i =0; i< n; i++){
		if ( sanPham[i].maSP == input ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == -1 ){
		printf("\n Khong co ma san pham can sua!");
	}else{
		printf("\nNhap ten san pham: ");
		fgets(sanPham[index].tenSP , 50, stdin);
		sanPham[index].tenSP[strlen(sanPham[index].tenSP) -1] = '\0' ;
		
		printf("Gia nhap: ");
		scanf("%f", &sanPham[index].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sanPham[index].giaBan);
		printf("So luong: ");
		scanf("%d", &sanPham[index].soLuong);
		fflush(stdin);
			
		printf("\nDanh sach ket qua: ");
		for ( int i = 0; i< n ; i++){
			printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
			printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
			printf("\n Gia ban: %.2f", sanPham[i].giaBan);
			printf("\n So luong: %d", sanPham[i].soLuong);
		}
	}
}

void sort( SanPham sanPham[], int n ){
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
				if ( sanPham[j].giaBan > sanPham[j+1].giaBan  ){
					SanPham temp = sanPham[j];
	                sanPham[j] = sanPham[j+1];
	                sanPham[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( sanPham[j].giaBan < sanPham[j+1].giaBan  ){
					SanPham temp = sanPham[j];
	                sanPham[j] = sanPham[j+1];
	                sanPham[j+1] = temp;
				}
			}
		}
	}
	
	printf("\nDanh sach sap xep: ");
	for ( int i = 0; i< n ; i++){
		printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
		printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
		printf("\n Gia ban: %.2f", sanPham[i].giaBan);
		printf("\n So luong: %d", sanPham[i].soLuong);
	}
}

void search( SanPham sanPham[], int n ){
	char input[50];
	int count = 0;
	
	fflush(stdin);
	printf("\nNhap ten san pham can tim: ");
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strstr(sanPham[i].tenSP, input) != NULL ){
			count = 1;
			printf("\nKet qua tim kiem: ");
			printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
			printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
			printf("\n Gia ban: %.2f", sanPham[i].giaBan);
			printf("\n So luong: %d", sanPham[i].soLuong);
		}
	}

	if ( count == 0 ) printf("\n Khong tim thay san pham!");
}

void sell( SanPham sanPham[], int n, float *rev ){
	int id, check = 0, index, qty;
	printf("\nNhap ma san pham can ban: ");
	scanf("%d", &id);
	
	for ( int i = 0; i<n ; i++){
		if ( sanPham[i].maSP == id ) {
			check = 1;
			index = i;
			break;
		}
	}
	
	if ( check == 0){
		printf("\n ID k ton tai!");
	}else{
		printf("\nNhap so luong ban: ");
		scanf("%d", &qty);
		
		if ( sanPham[index].soLuong == 0 ){
			printf("\nSan pham het hang!");
		}else if ( sanPham[index].soLuong < qty ){
			printf("\nSan pham khong du so luong!");
		}else{
			sanPham[index].soLuong -= qty;
			*rev += sanPham[index].giaBan * qty ;
			
			printf("\nKet qua ban san pham: ");
			for ( int i = 0; i< n ; i++){
				printf("\n\n %d. %s", sanPham[i].maSP, sanPham[i].tenSP );
				printf("\n Gia nhap: %.2f", sanPham[i].giaNhap);
				printf("\n Gia ban: %.2f", sanPham[i].giaBan);
				printf("\n So luong: %d", sanPham[i].soLuong);
			}
		}
	}
}

void revenue( float rev ){
	printf("\nDoanh thu hien tai: %.2f", rev);
}

