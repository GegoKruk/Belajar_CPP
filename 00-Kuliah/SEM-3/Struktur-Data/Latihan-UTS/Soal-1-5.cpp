/*
SOAL NON-CODING UTS STRUKTUR DATA 2026

1.  a.  Struktur Data berbeda dengan tipe data. Struktur data adalah sekumpulan tipe data dan kode yang disusun membentuk sebuah struktur dan menjalankan
        skema logika tertentu. Jadi lebih ke sebuah unit yang memiliki konsep dan skema. berbeda dengan tipe data, dimana itu adalah satuan tunggal jenis data
        dan memiliki sifat individual masing2, seperti string untuk teks, int untuk bilangan bulat, float untuk ganjil, dll
        
    b.  Tentukan Tipe Data :
        NIM = String
        Nama Mahasiswa = String
        Semester = Int
        IPK = float

        Menurut saya linked list dengan berbagai alasan:
        1.  Linked list super fleksibel isinya, dimana mahasiswa itu fleksibel juga jumlahnya, bisa aja dia DO, bisa aja pindah kampus, sehingga penerapan
            Linked list sangat cocok dan tidak kaku.
        2.  Menggunakan struct, walau array of struct juga bisa sih, tapi ini didukung oleh nomer 1 terkait fleksibilitas jumlah data
        3.  Tidak perlu repot2 menggeser array jika ada mahasiswa yang lulus aatau keluar, apalgi menggunakan double linked list dan sorted sekalian sehingga
            urut sesuai NIM


2.  Karena dalam CPP, penyisipan tanpa digeser akan menimpa data yang ada saat itu. sehingga proses pergeseran harus dilakukan untuk meengamankan data setelahnya.
    Kenapa harus dari kanan? karena kalau dari kiri gabisa dong, harus digeser satu per satu dari kanan. kalaupun dari kiri nanti malah menimpa satu per satu,
    menimbulkan kekacauan data (hilang tertimpa) seperti efek domino

3.  Perbandingan linked list dengan array
    a. Alokasi Memori
        Array       : Berurutan (contiguous)
        Linked List : Acak/berantakan (Non-contiguous)

    b. Ukuran 
        Array       : Tetap (Fixed) 
        Linked List : Dinamis (Bertambah/berkurang)

    c. Akses Element 
        Array       : Sangat cepat O(1) 
        Linked List : Lambat O(n) - Harus di runtut atau telusuri satu per satu

    d. Penyisipan/Penghapusan di Akhir 
        Array       : O(1)
        Linked List : O(1)

    e. Penyisipan/Penghapusan di Tengah 
        Array       : O(n) - harus geser elemen2 dibelakangnyya
        Linked List : O(1) - Mengubah pointer dan koneksinya

    f. Overhead Memori 
        Array       : Aman
        Linked List : Tinggi, perlu memori tambahan untuk pointer

4.  a.  Karena linked list sepenuhnya bergantung pada alamat memori tiap node yang saling terhubung
        Jika salah  pengubahan pointer dapat menyebabkaan rantai antar node (gerbong) terputus dan kehilangan akses node berikut/senelumnya

    b.  Memory leak atau kebocoran memori adalah fenomena dalam manajemen memori dimana program mengalokasikan ruang memori di heap, namun gagal membebaskan atau
        mengosongkan memori tersebut ke sistem operasi setelah tidak digunakan. Jika terjadi secara terus menerus, memori akan habis oleh sampah program
        Biasanya terjadi karena lupa delete object node, lupa menimpa pointer dengan memori baru, dll 

5.  Program akan menjalankan function sisipNilai
    Nilai baru akan masuk ke function, lalu nilai baru akan dimasukkan ke dalam newNode yang telah dibuat didalam function, Node *newNode = new Node();, 
    newnode -> nilai = nilaiBaru;, lalu set next atau prev (tergantung jenis linked list) ke nullptr semuanya. lalu cek dulu apakah list masih kosong? 
    karenaa sudah ada isinya 10, 20, dan 30, maka kondisi ini lolos. lalubarulah masuk ke kondisi else, head di set ke newnode 

    Alokasi Memori: Buat node baru (newNode) di heap memory dan isi nilainya dengan 5.
    
    Penyambungan Pointer: 
        Atur pointer next dari newNode agar menunjuk ke node tempat head berada saat ini (yaitu node 10)
        newNode->next = head
        
    Pembaruan Head: 
        Pindahkan pointer head agar menunjuk ke newNode
            head = newNode

    struct Node {
        int data;
        Node* next;
    };

    void insertFirst(Node* &head, int nilaiBaru) {

        // 1. Buat node baru di memory heap
        Node* newNode = new Node();
        newNode->data = nilaiBaru; // nilaiBaru = 5
        
        // 2. Hubungkan node baru ke head yang lama (node 10)
        newNode->next = head;
        
        // 3. Perbarui head ke node baru
        head = newNode;
        
    }
*/