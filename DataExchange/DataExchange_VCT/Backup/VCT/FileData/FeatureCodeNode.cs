///////////////////////////////////////////////////////////
//  FeatureCodeNode.cs
//  Implementation of the Class FeatureCodeNode
//  Generated by Enterprise Architect
//  Created on:      08-四月-2011 13:45:30
//  Original author: Administrator
///////////////////////////////////////////////////////////




namespace DIST.DGP.DataExchange.VCT.FileData {
	/// <summary>
	/// VCT要素编码节点类
	/// </summary>
	public class FeatureCodeNode {

		/// <summary>
		/// 要素代码
		/// </summary>
        public string FeatureCode
        {
            get
            {
                return m_strFeatureCode;
            }
            set
            {
                m_strFeatureCode = value;
            }
        }
        private string m_strFeatureCode;

		/// <summary>
		/// 要素名称
		/// </summary>
        public string FeatureName
        {
            get
            {
                return m_strFeatureName;
            }
            set
            {
                m_strFeatureName = value;
            }
        }
        private string m_strFeatureName;

		/// <summary>
		/// 图形类型
		/// </summary>
        public string GeometryType
        {
            get
            {
                return m_strGeometryType;
            }
            set
            {
                m_strGeometryType = value;
            }
        }
        private string m_strGeometryType;

		/// <summary>
		/// 数据表名
		/// </summary>
        public string TableName
        {
            get
            {
                return m_strTableName;
            }
            set
            {
                m_strTableName = value;
            }
        }
        private string m_strTableName;

        public FeatureCodeNode()
        {
        }

		public FeatureCodeNode(string strLine)
        {
            string[] arrValue = strLine.Split(HeadNode.Separator);
            if (arrValue.Length > 3)
            {
                m_strFeatureCode = arrValue[0];
                m_strFeatureName = arrValue[1];
                m_strGeometryType = arrValue[2];
                m_strTableName = arrValue[3];
            }
		}

		~FeatureCodeNode(){

		}

		public virtual void Dispose(){

		}
        /// <summary>
        /// 输出VCT节点
        /// </summary>
        public override string ToString()
        {
            return this.m_strFeatureCode + HeadNode.Separator.ToString() + this.m_strFeatureName + HeadNode.Separator.ToString() + this.m_strGeometryType + HeadNode.Separator.ToString() + this.m_strTableName;
        }

	}//end FeatureCodeNode

}//end namespace FileData