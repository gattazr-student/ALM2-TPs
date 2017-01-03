#ifndef _RS232_H
void startup_init_rs232(unsigned int line, int word_length, 
                int nb_stop, int parity, int rx_mode, int tx_mode,
                int loopback, int dsr, int baud, int rx_it_en);

void _startup_init_rs (void);
int _setup_speed_rs(unsigned int line, unsigned long baud);
#endif
