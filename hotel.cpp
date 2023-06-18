#include <iostream>
#include <string>

using namespace std;

// Fungsi ini digunakan untuk mencetak rincian pemesanan kamar tertentu
void printBookingDetails(int roomNumber, string roomType, int numberOfGuests, double roomRate)
{
  cout << "\t\tAnda telah memesan nomor kamarr " << roomNumber << " (" << roomType << ") Untuk " << numberOfGuests << " Tamu dengan Tarif Rp." << roomRate << ".000"<< " per Malam." << endl;
}

// Fungsi ini digunakan untuk menghitung total biaya pemesanan
double calculateTotalCost(int numberOfRooms, int numberOfNights, double roomRate, int currentRooms)
{
       // Jika kita telah mengulang semua kamar, kembalikan 0
  if (currentRooms > numberOfRooms)
  {
    return 0;
  }
    else {
         // Jika tidak, tambahkan biaya kamar saat ini ke total dan panggil fungsi lagi dengan kamar berikutnya
          return calculateTotalCost(numberOfRooms, numberOfNights, roomRate, currentRooms + 1) + numberOfNights * roomRate;
    }
}

int main()
{
  int numberOfNights;
  string hotelName;
  int roomNumber;
  int numberOfRooms;
  string roomType;
  int numberOfGuests;
  double roomRate;
  double totalCost;

  cout << "\t\t ------ Welcome to the RedDoors booking program! ------" << endl;
  cout << "\n\t\t Di Mohon Masukan Nama hotel yang anda ingin Booking: ";
  getline(cin, hotelName);

  cout << "\tMasukkan jumlah kamar yang ingin Anda pesan: ";
  cin >> numberOfRooms;

  cout << "\tMasukkan jumlah malam Anda akan menginap di hotel: ";
  cin >> numberOfNights;

  cout << " \n\t\t\t Terimakasih Sudah Booking! " << numberOfRooms << " Kamar Di " << hotelName << "." << endl;

  for (int i = 1; i <= numberOfRooms; i++)
  {
    cout << "\tSilakan masukkan no kamar " << i << ":";
    cin >> roomNumber;

    cout << "\tMau Pilih Tipe Apa (single/double/suite): ";
    cin >> roomType;

    cout << "\tHarap masukkan jumlah tamu untuk kamar " << i << ": ";
    cin >> numberOfGuests;

    cout << "\tharga Tersedia saat ini (10/20/50) Silakan Pilih " << "Untuk Kamar "<< i << ": ";
    cin >> roomRate;
    
    // menngulang setiap ruangan
    for (int j = 1; j <= numberOfGuests; j++)
     {
        cout << "\n\tSilakan masukkan nama tamu: \n";
        string guestName;
        cout << "\tTamu " << j << ": " << guestName;
        cin >> guestName;
     }

        printBookingDetails(roomNumber, roomType, numberOfGuests, roomRate);

      totalCost = calculateTotalCost(numberOfRooms, numberOfNights, roomRate, 1);
    
    cout << "\n\t\t====================     Invoice      =================" << endl;

    cout << "\t\tTotal biaya pemesanan Anda untuk " << numberOfNights << " Malam adalah:\n\t\t Rp." << totalCost << "000." << endl;

    cout << "\t\tAnda telah memesan nomor kamar " << roomNumber << " (" << roomType << ") Untuk " << numberOfGuests << " Tamu dengan tarif:\n\t\t Rp." << roomRate << "000" << " per Malam." << "\n\n";
  }
  cout << "\t\t============================================================" << endl;
  cout << "\t\tTotal biaya pemesanan Anda untuk " << numberOfNights << " Malam: Rp." << totalCost << "000." << endl;

  return 0;
}
