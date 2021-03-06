#ifndef SENTRY_INTERNAL_HPP_INCLUDED
#define SENTRY_INTERNAL_HPP_INCLUDED
#include <sentry.h>
#include <map>
#include <string>

const sentry_options_t *sentry_get_options(void);

struct SentryInternalOptions {
    std::string minidump_url;
    /* The unique run identifier */
#ifdef _WIN32
    std::wstring run_id;
    /* The full path to the current run */
    std::wstring run_path;

    std::map<std::string, std::wstring> attachments;
#else
    std::string run_id;
    /* The full path to the current run */
    std::string run_path;

    std::map<std::string, std::string> attachments;
#endif
    sentry_options_t options;
};

static const int BREADCRUMB_MAX = 100;
static const int ATTACHMENTS_MAX = 100;
static const int ATTACHMENTS_KEY_LENGTH_MAX = 50;
static const int ATTACHMENTS_PATH_LENGTH_MAX = 260;
static const int MINIDUMP_URL_MAX_LENGTH = 150;

/* Refs are used to keep track of current breadcrumb file */
#ifdef _WIN32
static const wchar_t *SENTRY_EVENT_FILE_NAME = L"sentry-event.mp";
static const wchar_t *MINIDUMP_FILE_EXTENSION = L".dmp";
static const wchar_t *BREADCRUMB_FILE_1 = L"sentry-breadcrumb1.mp";
static const wchar_t *BREADCRUMB_FILE_2 = L"sentry-breadcrumb2.mp";
#else
static const char *SENTRY_EVENT_FILE_NAME = "sentry-event.mp";
static const char *MINIDUMP_FILE_EXTENSION = ".dmp";
static const char *BREADCRUMB_FILE_1 = "sentry-breadcrumb1.mp";
static const char *BREADCRUMB_FILE_2 = "sentry-breadcrumb2.mp";
#endif
/* Names used when uploading to Sentry */
static const char *SENTRY_EVENT_FILE_ATTACHMENT_NAME = "__sentry-event";
static const char *SENTRY_BREADCRUMB1_FILE_ATTACHMENT_NAME =
    "__sentry-breadcrumb1";
static const char *SENTRY_BREADCRUMB2_FILE_ATTACHMENT_NAME =
    "__sentry-breadcrumb2";

static const char *SENTRY_SDK_VERSION = "0.0.1";
#endif
