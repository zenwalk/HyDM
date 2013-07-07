﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;

namespace Hy.Metadata
{
    public class MetaStandardHelper
    {
        public MetaStandardHelper(MetaStandard metaStandard)
        {
        }

        public static MetaStandard GetStandardByName(string strName)
        {
            IList<MetaStandard> standardList = Environment.NhibernateHelper.GetObjectsByCondition<MetaStandard>(string.Format("from MetaStandard mStandard where mStandard.Name='{0}'", strName));
            if (standardList == null || standardList.Count == 0)
                return null;

            return standardList[0];
        }

        public static MetaStandard GetStandardById(string id)
        {
            return  Environment.NhibernateHelper.GetObjectById<MetaStandard>(id);          
        }

        public static IList<MetaStandard> GetAll()
        {
            return Environment.NhibernateHelper.GetAll<MetaStandard>();
        }

        public static string ErrorMessage { get; private set; }

        /// <summary>
        /// 删除字典项
        /// </summary>
        /// <param name="standard"></param>
        /// <returns></returns>
        public static bool DeleteStandard(MetaStandard standard)
        {
            try
            {
                // 记录
                Environment.NhibernateHelper.DeleteObject(standard);
                Environment.NhibernateHelper.Flush();

                // 删除数据表
                if (Environment.AdodbHelper.TableExists(standard.TableName))
                {
                    if (Environment.AdodbHelper.ExecuteSQL(string.Format("Drop table {0}", standard.TableName))<1)
                    {
                        ErrorMessage = "标准已删除，但未删除数据";
                    }
                }
               
                return true;
            }
            catch (Exception exp)
            {
                Environment.Logger.AppendMessage(Define.enumLogType.Error, string.Format("删除元数据标准时出错：{0}", exp.ToString()));

                return false;
            }
        }

        /// <summary>
        /// 保存字典项
        /// </summary>
        /// <param name="standard"></param>
        /// <returns></returns>
        public static bool SaveStandard(MetaStandard standard)
        {
            try
            {
                // 记录
                Environment.NhibernateHelper.SaveObject(standard);
                Environment.NhibernateHelper.Flush();

                // 创建表
                if (Environment.AdodbHelper.TableExists(standard.TableName))
                {
                    Environment.AdodbHelper.ExecuteSQL(string.Format("Drop table {0}", standard.TableName));

                }

                return true;
            }
            catch (Exception exp)
            {
                Environment.Logger.AppendMessage(Define.enumLogType.Error, string.Format("保存元数据标准时出错：{0}", exp.ToString()));

                return false;
            }
        }

        public static void ReLoadItem(MetaStandard standard)
        {
            Environment.NhibernateHelper.RefreshObject(standard, Define.enumLockMode.UpgradeNoWait);
        }

        public static DataTable GetMetaData(MetaStandard standard)
        {
           return Environment.AdodbHelper.ExecuteDataTable(string.Format("select * from {0}",standard.TableName));
        }

        public static string GetSQLFromField(FieldInfo fInfo)
        {
            if (fInfo == null)
                return null;

            string strSQL="";
            string strTypeKey = GetTypeKey(fInfo.Type);
            switch (fInfo.Type)
            {
                case enumFieldType.String:
                    if (string.IsNullOrEmpty(strTypeKey ))
                        strTypeKey = "varchar";

                    strSQL=string.Format("{0}({1}) {2}",strTypeKey,
                        fInfo.Length>0?fInfo.Length:50,fInfo.NullAble?"":"Not Null");
                    break;

                case enumFieldType.Int:
                    if (string.IsNullOrEmpty(strTypeKey))
                        strTypeKey = "Int";
                    strSQL = strTypeKey;
                    break;

                case enumFieldType.Decimal:
                    if (string.IsNullOrEmpty(strTypeKey))
                        return "numeric";

                    int fLen= fInfo.Length>0?fInfo.Length:5;
                    strSQL = string.Format("{0}({1},{2})", strTypeKey,
                       fLen,
                       fInfo.Precision > fLen ? fLen : fInfo.Precision);                    

                    break;

                case enumFieldType.DateTime:
                    if (string.IsNullOrEmpty(strTypeKey))
                        strTypeKey = "DateTime";

                    strSQL = strTypeKey;

                    break;

                case enumFieldType.Image:
                case enumFieldType.Binary:
                    if (string.IsNullOrEmpty(strTypeKey))
                        strTypeKey = "Image";

                    strSQL = strTypeKey;
                    break;

                default:
                    return "varchar";
            }

            return strSQL;
        }

        private static string[] m_TypeItemKey =
        {
            ConstDefine.Type_Key_String,
            ConstDefine.Type_Key_Int,
            ConstDefine.Type_Key_Decimal,
            ConstDefine.Type_Key_DateTime,
            ConstDefine.Type_Key_Binary,
            ConstDefine.Type_Key_Binary
        };
        private static string GetTypeKey(enumFieldType fType)
        {
            return Environment.NhibernateHelper.GetObject<string>(
                string.Format("select cfgItem.ItemValue from ConfigItem cfgItem where cfgItem.ItemName='{0}'",m_TypeItemKey[(int)fType]));
        }

        public static DataTable GetMetadata(string strTable, string strClause, int countPerPage, int pageIndex, ref int errCount)
        {
            if (errCount < 0)
            {
                errCount = Convert.ToInt32(Environment.AdodbHelper.ExecuteScalar(string.Format("select count(0) from {0}", strTable)));
            }

            int resultCount = countPerPage;
            if (countPerPage * (pageIndex + 1) > errCount)
                resultCount = errCount - countPerPage * pageIndex;

            string strSQL = Environment.NhibernateHelper.GetObject<string>(string.Format("select cfgItem.ItemValue from ConfigItem cfgItem where cfgItem.ItemName='{0}'", strTable));
            if (string.IsNullOrEmpty(strSQL))
            {
                strSQL = "select top {3} * from (select top {1}*({2}-1) * from {0} where {4} order by id acs) order by id desc";
            }

            object[] objParams = { strTable, countPerPage, pageIndex, resultCount, strClause };
            strSQL = string.Format(strSQL, objParams);

            return Environment.AdodbHelper.ExecuteDataTable(strSQL);
        }

        public static bool UpdateMeatadata(MetaStandard standard, DataTable dtData)
        {
            if (standard == null)
                return false;

            return Environment.AdodbHelper.UpdateTable(standard.TableName, dtData);
        }
    }
}
