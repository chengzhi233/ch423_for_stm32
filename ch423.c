#include "ch423.h"
#include "stm32f1xx_hal.h"

void CH423_I2c_Start( void )
{
    CH423_SDA_SET;
    CH423_SDA_D_OUT;
    CH423_SCL_SET;
    CH423_SCL_D_OUT;
    DELAY_0_1US;
    CH423_SDA_CLR;
    DELAY_0_1US;      
    CH423_SCL_CLR;
}

void CH423_I2c_Stop( void )
{
    CH423_SDA_CLR;
    DELAY_0_1US;
    CH423_SCL_SET;
    DELAY_0_1US;
    CH423_SDA_SET;
    DELAY_0_1US;
}

void CH423_I2c_WrByte( unsigned char dat ) 
{
    unsigned char i;
    for( i = 0; i != 8; i++ )
    {
        if( dat&0x80 ) { CH423_SDA_SET; }
        else { CH423_SDA_CLR; }
        DELAY_0_1US;
        CH423_SCL_SET;
        dat<<=1;
        DELAY_0_1US;
        CH423_SCL_CLR;
    }
    CH423_SDA_SET;
    DELAY_0_1US;
    CH423_SCL_SET;
    DELAY_0_1US;
    CH423_SCL_CLR;
}

unsigned char CH423_I2c_RdByte( void )
{
    unsigned char dat,i;
    CH423_SDA_SET;
    CH423_SDA_D_IN;
    dat=0;
    for( i = 0; i != 8; i++ )
    {
        DELAY_0_1US;
        CH423_SCL_SET;
        DELAY_0_1US;
        dat<<=1;
        if(CH423_SDA_IN) 
					dat++;
        CH423_SCL_CLR;
    }
    CH423_SDA_SET;
    DELAY_0_1US;
    CH423_SCL_SET;
    DELAY_0_1US;
    CH423_SCL_CLR;
    return(dat);
}

void CH423_Write( unsigned short cmd )
{
    CH423_I2c_Start();
    CH423_I2c_WrByte( ( ( unsigned char )( cmd>>7 ) & CH423_I2C_MASK ) | CH423_I2C_ADDR1 );
    CH423_I2c_WrByte( ( unsigned char ) cmd );
    CH423_I2c_Stop();
}

void CH423_WriteByte( unsigned short cmd )
{
    CH423_I2c_Start();
    CH423_I2c_WrByte( ( unsigned char )( cmd>>8 ) );
    CH423_I2c_WrByte( ( unsigned char ) cmd );
    CH423_I2c_Stop();  
}

unsigned char CH423_ReadByte()
{
    unsigned char din;
    CH423_I2c_Start();
    CH423_I2c_WrByte( CH423_RD_IO_CMD );
    din=CH423_I2c_RdByte();
    CH423_I2c_Stop();
    return( din );
}
