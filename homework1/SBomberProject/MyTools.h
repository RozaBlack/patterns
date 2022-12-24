#pragma once

#include <stdint.h>
#include <string>

namespace MyTools {

    // Палитра цветов от 0 до 15
    enum ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };

	//=============================================================================================
    class ScreenSingleton
    {
    public:
        static ScreenSingleton& getInstance()
        {
            static ScreenSingleton theInstance;
            return theInstance;
        }
        void ClrScr();
        void __fastcall GotoXY(double x, double y);
        uint16_t GetMaxX();
        uint16_t GetMaxY();
        void SetColor(ConsoleColor color);
    private:
        ScreenSingleton() { }
        ScreenSingleton(const ScreenSingleton& root) = delete;
        ScreenSingleton& operator=(const ScreenSingleton&) = delete;
    };

	/*void ClrScr();

	void __fastcall GotoXY(double x, double y);

	uint16_t GetMaxX();

	uint16_t GetMaxY();

    void SetColor(ConsoleColor color);*/

	//=============================================================================================
    class FileLoggerSingletone
    {
    public:
        virtual void __fastcall OpenLogFile(const std::string& FN) = 0;
        virtual void CloseLogFile() = 0;
        virtual void __fastcall WriteToLog(const std::string& str) = 0;
        virtual  void __fastcall WriteToLog(const std::string& str, int n) = 0;
        virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
    private:
    };

    class RealFileLoggerSingletone : public FileLoggerSingletone
    {
    public:
        static RealFileLoggerSingletone& getInstance()
        {
            static RealFileLoggerSingletone theInstance;
            return theInstance;
        }
        void __fastcall OpenLogFile(const std::string& FN) override;
        void CloseLogFile() override;
        void __fastcall WriteToLog(const std::string& str) override;
        void __fastcall WriteToLog(const std::string& str, int n) override;
        void __fastcall WriteToLog(const std::string& str, double d) override;
    private:
        RealFileLoggerSingletone() { }
        RealFileLoggerSingletone(const RealFileLoggerSingletone& root) = delete;
        RealFileLoggerSingletone& operator=(const RealFileLoggerSingletone&) = delete;
    };

	//=============================================================================================
    class LoggerSingletone : public FileLoggerSingletone
    {
        public:
            static LoggerSingletone& getInstance()
            {
                static LoggerSingletone theInstance;
                return theInstance;
            }
            static inline int iter;
            virtual void __fastcall OpenLogFile(const std::string& FN) {
                fileLoggerSingletone->OpenLogFile(FN);
            };

            virtual void CloseLogFile() {
                fileLoggerSingletone->CloseLogFile();
            };

            virtual void __fastcall WriteToLog();

            virtual void __fastcall WriteToLog(const std::string& str) {
                WriteToLog();
                fileLoggerSingletone->WriteToLog(str);
            };

            virtual  void __fastcall WriteToLog(const std::string& str, int n) {
                WriteToLog();
                fileLoggerSingletone->WriteToLog(str, n);
            };

            virtual void __fastcall WriteToLog(const std::string& str, double d) {
                WriteToLog();
                fileLoggerSingletone->WriteToLog(str, d);
            };

        private:
            FileLoggerSingletone* fileLoggerSingletone;
            LoggerSingletone() {
                fileLoggerSingletone = &RealFileLoggerSingletone::getInstance();
            }
            LoggerSingletone(const RealFileLoggerSingletone& root) = delete;
            LoggerSingletone& operator=(const RealFileLoggerSingletone&) = delete;

    };

};