
bool Utils_IsN3DS(void);
void Utils_U16_To_U8(u8 *buf, const u16 *input, size_t bufsize);
void Utils_U8_To_U16(u16 *buf, const u8 *input, size_t bufsize);
char *Utils_Basename(const char *filename);
void Utils_GetSizeString(char *string, u64 size);
void Utils_SetMax(int *set, int value, int max);
void Utils_SetMin(int *set, int value, int min);
int Utils_Alphasort(const void *p1, const void *p2);
void Utils_AppendArr(char subject[], const char insert[], int pos);
