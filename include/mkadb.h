//
// Created by sparky on 5/21/23.
//

#ifndef MKADB_MKADB_H
#define MKADB_MKADB_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <vector>
#include <expected>
// mkadb - Kemalpaşa NoSQL embedded database project
// Copyright (c)2023 Yiğit Cemal Öztürk <admin@yigitovski.com>
// Licensed under GPLv3
namespace com {
    namespace yigitovski {
        namespace mkadb {
            typedef struct TableInfo {
                typedef struct ColumnInfo {
                    typedef enum class ColumnType {
                        DB_NULL,
                        STRING,
                        // Signed Integer Types
                        SINT8, SINT16, SINT32, SINT64, SINT128, SINT256,
                        // Unsigned Integer Types
                        UINT8, UINT16, UINT32, UINT64, UINT128, UINT256,

                        // Real Number Types
                        R_IEEE754_32, R_IEEE754_64, R_IEEE754_80,
                        // Binary Data Types
                        BLOB, BOOLEAN, BINARY,

                        // Date and Time
                        ISO8601, UNIX_TS
                    } ColumnType;
                    typedef enum class ColumnFlags {
                        NOT_NULL, PRIMARY_KEY, FOREIGN_KEY, UNIQUE, NULLABLE
                    } ColumnFlags;
                    char *name;
                    ColumnType type;
                    ColumnFlags flags;
                    std::optional<uint32_t> length;
                } Column;

                char *name;
            } Table;
            /// Represents a Kemaplpaşa Database Instance
            class KemalpasaDB {
            public:
                KemalpasaDB();
                ~KemalpasaDB();
                /// Creates a table in this instance
                Table& createTable(Table tableInfo);
            };
        }
    }
}
#endif //MKADB_MKADB_H
